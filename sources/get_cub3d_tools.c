/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub3d_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:54:41 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:54:42 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*ft_strdupstr(char *s1, t_infos *infos, int type)
{
	int		n;
	char 	*s;

	s1 = skip(s1);
	if ((infos->check & type) != type)
	{
		n = ft_strlen(s1);
		if (!( s= (char *) malloc(sizeof(char) * (n + 1))))
			return (NULL);
		ft_strcpy(s, s1);
		infos->check |= type;
		return (s);
	}
	else
	{
		perror("Plusieurs fois la meme infos");
		return (NULL);
	}
}

int		ft_allocmap(char *line, t_infos *infos)
{
	char	**tmp;
	int 	i;

	i = 0;
	if (infos->raw++ == 0)
	{
		if (!(*(infos->map) = ft_strdup(line)))
			return (-1);
	}
	else
	{
		tmp = infos->map;
		if (!(infos->map = malloc(sizeof(char*) * (infos->raw + 1))))
			return (-1);
		while (i < infos->raw - 1)
		{
			infos->map[i] = ft_strdup(tmp[i]);
			i++;
		}
		infos->map[i] = ft_strdup(line);
	}
	return (0);
}
