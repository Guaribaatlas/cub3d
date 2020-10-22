/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:54:47 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:55:48 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int main()
{
	t_infos infos;
	int i;

	i = 0;
	infos.player =0;
	ft_initialize(&infos);
	ft_get_cub3d(&infos);
	if (ft_check_map(infos.map, &infos) != -1 && parser_info(&infos) != -1)
	{
		ft_cub3d(&infos);
		return (0);
	}
	return(0);
}
