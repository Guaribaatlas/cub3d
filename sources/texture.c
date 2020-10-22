/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:52:22 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 14:52:23 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void 	ft_get_texture(t_cub *cub, t_infos *infos)
{
	int i;

	i = -1;
	while (++i < TEXTURES)
	{
		cub->text[i].width = 0;
		cub->text[i].height = 0;
		if ((cub->text[i].data = mlx_xpm_file_to_image(cub->mlx,
												   infos->path[i],
												  &cub->text[i].width,
												  &cub->text[i].height)))
		{
			cub->text[i].txt = (int *)mlx_get_data_addr(cub->text[i].data,
												&cub->text[i].bpp,
												&cub->text[i].sl,
												&cub->text[i].endian);
		}
		else
		{
			perror("problem texture");
			return ;
		}
	}
}
t_text 	select_text(t_cub *cub)
{
	if (cub->side == 1)
	{
		if (cub->raydir[Y] >= 0)
			return (cub->text[WEST]);
		else
			return (cub->text[EAST]);
	}
	else
	{
		if (cub->raydir[X] >= 0)
			return (cub->text[NORTH]);
		else
			return (cub->text[SOUTH]);
	}
}
char 	*skip(char *s1)
{
		while ((*s1 >= 65 && *s1 <= 90) || *s1 == ' ')
			s1++;
		return(s1);

}
