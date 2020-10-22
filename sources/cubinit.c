/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:53:55 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:53:57 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	initwhile(t_cub *cub, int x, t_infos *infos)
{
	cub->cam = 2 * x / (double)infos->re[X] - 1;
	cub->raydir[X] = cub->dir[X] + cub->plane[X] * cub->cam;
	cub->raydir[Y] = cub->dir[Y] + cub->plane[Y] * cub->cam;
	cub->map[X] = (int)cub->pos[X];
	cub->map[Y] = (int)cub->pos[Y];
	cub->ddist[X] = fabs(1 / cub->raydir[X]);
	cub->ddist[Y] = fabs(1 / cub->raydir[Y]);
	cub->side = 0;
	cub->hit = 0;
}

void	get_dir(char pos, t_cub *cub)
{
	if (pos == 'N')
	{
		cub->dir[X] = 0;
		cub->dir[Y] = -1;
		cub->plane[Y] = 0;
		cub->plane[X] = 0.66;
	}
	if (pos == 'S')
	{
		cub->dir[X] = 0;
		cub->dir[Y] = 1;
		cub->plane[Y] = 0;
		cub->plane[X] = -0.66;
	}
	if (pos == 'E')
	{
		cub->dir[X] = 1;
		cub->dir[Y] = 0;
		cub->plane[Y] = 0.66;
		cub->plane[X] = 0;
	}
	if (pos == 'W')
	{
		cub->dir[X] = -1;
		cub->dir[Y] = 0;
		cub->plane[Y] = -0.66;
		cub->plane[X] = 0;
	}
}

void	get_playerposdir(t_infos *infos, t_cub *cub)
{
	int x;
	int y;

	y = 0;
	while (infos->map[y])
	{
		x = 0;
		while (infos->map[y][x])
		{
			if (infos->map[y][x] == 'N' || infos->map[y][x] == 'S' ||
				infos->map[y][x] == 'W' || infos->map[y][x] == 'E')
			{
				cub->pos[X] = x;
				cub->pos[Y] = y + 0.5;
				get_dir(infos->map[y][x], cub);
				return ;

			}
			x++;
		}
		y++;
	}
}

void	ft_initcub(t_infos *infos, t_cub *cub)
{
	cub->textured = 1;
	cub->frame = NULL;
	cub->mlx = mlx_init();
	cub->exit = 0;
	cub->rotspeed = 0.025;
	cub->movespeed = 0.05;
	cub->win = mlx_new_window (cub->mlx, infos->re[X], infos->re[Y], "cub");
	get_playerposdir(infos, cub);
}
