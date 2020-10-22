/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:57:57 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:57:59 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"


char 	**unionchar(t_infos)
{
	char *ret[5]
	int i;

	i = 0;
	while(i < TEXTURES)
	{
		*ret[i] =
	}
}

void 	ft_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
}
