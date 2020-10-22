/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:55:10 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:55:12 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_resize(t_infos *infos)
{
	if (infos->re[0] > 1920)
		infos->re[0] = 1920;
	if (infos->re[0] < 400)
		infos->re[0] = 400;
	if (infos->re[1] > 1080)
		infos->re[1] = 1080;
	if (infos->re[1] < 200)
		infos->re[1] = 200;
}

void	ft_initialize(t_infos *infos)
{
 	infos->r = NULL;
 	infos->f = NULL;
	infos->c = NULL;
	infos->re[X] = 0;
	infos->re[Y] = 0;
	infos->fl[0] = -1;
	infos->fl[1] = -1;
	infos->fl[2] = -1;
	infos->ceil[0] = -1;
	infos->ceil[1] = -1;
	infos->ceil[2] = -1;
	infos->check = 0;
	infos->numsprite = 0;
}

int			ft_atoi_pt(char **str)
{
	long long	nb;

	nb = 0;
	while (**str == '\t' || **str == '\n' || **str == '\r' ||
		   **str == '\v' || **str == '\f' || **str == ' ' || **str == 'R' ||
			**str == 'C' || **str == 'F' || **str == ',')
		(*str)++;
	if (**str < '0' || **str > '9')
		return (-1);
	while (**str >= '0' && **str <= '9')
	{
		nb = ((nb * 10) + **str) - 48;
		(*str)++;
	}
	return (nb);
}
