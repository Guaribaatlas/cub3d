/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:54:34 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:54:35 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_checkstr(char *line, t_infos *infos)
{
		while ((*line == ' ' || *line == '\t') && infos->check < 255)
			line++;
		if (*line == 'R')
			infos->r = ft_strdupstr(line, infos, R);
		else if (*line == 'N' && *(line + 1) == 'O')
			infos->path[NORTH] = ft_strdupstr(line, infos, NO);
		else if (*line == 'S' && *(line + 1) == 'O')
			infos->path[SOUTH] = ft_strdupstr(line, infos, SO);
		else if (*line == 'S' && *(line + 1) != 'O' && infos->check < 255)
			infos->path[SPRITE] = ft_strdupstr(line, infos, S);
		else if (*line == 'W' && *(line + 1) == 'E')
			infos->path[WEST] = ft_strdupstr(line, infos, WE);
		else if (*line == 'E' && *(line + 1) == 'A')
			infos->path[EAST] = ft_strdupstr(line, infos, EA);
		else if (*line == 'F')
			infos->f = ft_strdupstr(line, infos, F);
		else if (*line == 'C')
			infos->c = ft_strdupstr(line, infos, C);
		else if (infos->check == 255)
			return (ft_allocmap(line, infos));
		return (0);
}

int 	ft_get_cub3d(t_infos *infos)
{
	int 	fd;
	char	*line;

	infos->map = malloc(sizeof(char*) * 1);
	fd = open("./map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (ft_checkstr(line, infos) == -1)
			return (-1);
	}
	if (ft_checkstr(line, infos) == -1)
		return (-1);
	return (0);
}
