/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:53:44 by jehaenec          #+#    #+#             */
/*   Updated: 2020/10/12 16:09:12 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_perpwall_drawstart_end(t_cub *cub, t_infos *infos)
{
	if (cub->side == 0)
	{
		cub->perpwalldist = (cub->map[X] - cub->pos[X] + (1 - cub->step[X]) /
				2) / cub->raydir[X];
	}
	else
	{
		cub->perpwalldist = (cub->map[Y] - cub->pos[Y] + (1 - cub->step[Y]) /
				2) / cub->raydir[Y];
	}
	cub->lineheight = (int)(infos->re[Y] / cub->perpwalldist);
	cub->drawstart = -cub->lineheight / 2 + infos->re[Y] / 2;
	if(cub->drawstart < 0)
		cub->drawstart = 0;
	cub->drawend = cub->lineheight / 2 + infos->re[Y] / 2;
	if(cub->drawend >= infos->re[Y])
		cub->drawend = infos->re[Y] - 1;
}

void	ft_textured(t_cub *cub, int x, t_infos *infos)
{
	t_text text;
	int y;

	y = 0;
	while (y < cub->drawstart)
	{
		cub->data[x + y * infos->re[X]] = 0xA564;
		y++;
	}
	text = select_text(cub);
	if (cub->side == 0)
		cub->wallx = cub->pos[Y] + cub->perpwalldist * cub->raydir[Y];
	else
		cub->wallx = cub->pos[X] + cub->perpwalldist * cub->raydir[X];
	cub->wallx -= floor(cub->wallx);
	cub->stp = 1.0 * text.height / cub->lineheight;
	cub->texx = (int)(cub->wallx * (double)text.height);
	cub->texpos = (cub->drawstart - infos->re[Y] / 2 + cub->lineheight / 2)
			*cub->stp;
	cub->color = 0;
	while (y < cub->drawend)
	{
		cub->texy = (int)cub->texpos & (text.height - 1);
		cub->texpos += cub->stp;
		cub->data[x + y++ * infos->re[X]] = text.txt[text.width * cub->texy +
									 cub->texx];
	}
	while (y < infos->re[Y])
	{
		cub->data[x + y * infos->re[X]] = 0x898580;
		y++;
	}
}

void	ft_draw(t_cub *cub, int x, t_infos *infos)
{
	int i;

	i = 0;\
	if (cub->textured == 0)
	{
		while (i < cub->drawstart)
		{
			cub->data[x + i * infos->re[X]] = 0xA564;
			i++;
		}
		while (i <= cub->drawend)
		{
			cub->data[x + i * infos->re[X]] = 0xED8509;
			i++;
		}
		while (i < infos->re[Y])
		{
			cub->data[x + i * infos->re[X]] = 0x898580;
			i++;
		}
	}
	else
		ft_textured(cub, x, infos);
}

void	ft_calsidedist(t_cub *cub)
{
	if(cub->raydir[X] < 0)
	{
		cub->step[X] = -1;
		cub->sidedist[X] = (cub->pos[X] - cub->map[X]) * cub->ddist[X];
	}
	else
	{
		cub->step[X] = 1;
		cub->sidedist[X] = (cub->map[X] + 1.0 - cub->pos[X]) * cub->ddist[X];
	}
	if(cub->raydir[Y] < 0)
	{
		cub->step[Y] = -1;
		cub->sidedist[Y] = (cub->pos[Y] - cub->map[Y]) * cub->ddist[Y];
	}
	else
	{
		cub->step[Y] = 1;
		cub->sidedist[Y] = (cub->map[Y] + 1.0 - cub->pos[Y]) * cub->ddist[Y];
	}
}

void	ft_dda(t_cub *cub, t_infos *infos)
{
	while (cub->hit == 0)
	{
		if (cub->sidedist[X] < cub->sidedist[Y])
		{
			cub->sidedist[X] += cub->ddist[X];
			cub->map[X] += cub->step[X];
			cub->side = 0;
		}
		else
		{
			cub->sidedist[Y] += cub->ddist[Y];
			cub->map[Y] += cub->step[Y];
			cub->side = 1;
		}
		if (infos->map[cub->map[Y]][cub->map[X]] == '1')
			cub->hit = 1;
	}
}
