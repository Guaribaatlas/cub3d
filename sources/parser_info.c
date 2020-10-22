/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:54:55 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:54:56 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_check_fl_ceil(t_infos *infos)
{
	if ((infos->fl[0] = ft_atoi_pt(&infos->f)) == -1)
		return (-1);
	if ((infos->fl[1] = ft_atoi_pt(&infos->f)) == -1)
		return (-1);
	if ((infos->fl[2] = ft_atoi_pt(&infos->f)) == -1)
		return (-1);
	if ((infos->ceil[0] = ft_atoi_pt(&infos->c)) == -1)
		return (-1);
	if ((infos->ceil[1] = ft_atoi_pt(&infos->c)) == -1)
		return (-1);
	if ((infos->ceil[2] = ft_atoi_pt(&infos->c)) == -1)
		return (-1);
	return (0);
}

int		ft_check_path(char *path)
{
	while (*path == ' ' || *path == '\t' || *path == 'N' || *path == 'O' ||
			*path == 'W' || *path == 'A' || *path == 'E' || *path == 'S')
			path++;
	if (*path == '.' && *(path + 1)  =='/')
	{
		while (*path)
		{
			if (*path == ' ' || *path == '\t')
				return (-1);
			path++;
		}
		return (0);
	}
	return (-1);
}

int		ft_check_texture(t_infos *infos)
{
	if (ft_check_path(infos->path[SPRITE]) == -1)
		return (-1);
	if (ft_check_path(infos->path[WEST]) == -1)
		return (-1);
	if (ft_check_path(infos->path[EAST]) == -1)
		return (-1);
	if (ft_check_path(infos->path[NORTH]) == -1)
		return (-1);
	if (ft_check_path(infos->path[SOUTH]) == -1)
		return (-1);
	return (0);
}

int		parser_info(t_infos *infos)
{
	if (infos->check != 255)
	{
		perror("infos manquante");
		return (-1);
	}
	if ((infos->re[X] = ft_atoi_pt(&infos->r)) == -1 ||
		(infos->re[Y] = ft_atoi_pt(&infos->r)) == -1)
	{
		perror("error in R");
		return (-1);
	}
	ft_resize(infos);
	if (ft_check_texture(infos) == -1)
	{
		perror("error texture path");
		return(-1);
	}
	if (ft_check_fl_ceil(infos) == -1)
	{
		perror("error in colors");
		return(-1);
	}
	return (0);
}
