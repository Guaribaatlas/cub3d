/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:55:04 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:55:05 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		check_all(char **map, int i, int j, t_infos *infos)
{
	if (map[j][i] == ' ')
	{
		if (j == infos->raw)
		{
			if (map[j][i + 1] != ' ' && map[j][i + 1] != '1'  &&
				map[j][i + 1] != '\0' && map[j][i + 1] != '\t')
				return (-1);
		}
		else
		{
			if ((map[j + 1][i] != ' ' && map[j + 1][i] != '1') &&
				(map[j][i + 1] != ' ' && map[j][i + 1] != '1') &&
					map[j][i + 1] != '\0')
				return (-1);
		}
	}
	if (map[j][i] != ' ' && map[j][i] != '1' && map[j][i] != '\0')
	{
		if (map[j + 1][i] == ' ' || map[j][i + 1] == ' ')
			return (-1);
	}
	return (0);
}

int		ft_check_map(char **map, t_infos *infos)
{
	int i;
	int j;

	j = -1;
	while(map[++j])
	{
		i = 0;
		while (map[j][i])
		{
			if (j > 1)
			{
				if (((int)ft_strlen(map[j - 1]) < i ) && (map[j][i] != '1' &&
				map[j][i] != ' '))
				{
					printf("map[%i][%i] = %c\n", j, i, map[j][i]);
					perror("trou dans la map");
					return (-1);
				}
			}
			if (map[j][i] == 2)
				infos->numsprite++;
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W' ||
				map[j][i] == 'E')
			{
				if (infos->player == 1)
				{
					perror("Plusieurs joueurs sur la map");
					return (-1);
				}
				infos->player = 1;
			}
			if (check_all(map, i, j, infos) == -1)
			{
				perror("trou dans la map");
				return (-1);
			}
			i++;
		}
	}
	if (infos->player == 0)
	{
		perror("pas de joueur sur la map");
		return (-1);
	}
	return (0);
}
