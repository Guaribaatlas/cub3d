/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:53:36 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:53:38 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_cub3d(t_infos *infos)
{
	t_hook	k_struct;
	t_cub	cub;
	int (*keyhook)(int, struct s_hook*);

	keyhook = &key_hook;
	ft_initcub(infos, &cub);
	k_struct.cub = &cub;
	k_struct.infos = infos;
	ft_rc(&k_struct);
	mlx_hook(cub.win,2 ,0 ,keyhook, &k_struct);
   if (cub.ext == 1)
   		return ;
	mlx_loop(cub.mlx);
}

void	ft_rc(t_hook *k)
{
	int x;

	x = 0;
	if (k->cub->frame == NULL)
	{
		k->cub->frame = mlx_new_image(k->cub->mlx, k->infos->re[X],
							   k->infos->re[Y]);
		k->cub->data = (int*)mlx_get_data_addr(k->cub->frame, &k->cub->bpp,
										 &k->cub->sl, &k->cub->endian);
	}
	ft_get_texture(k->cub, k->infos);
	while (x < k->infos->re[X])
	{
		initwhile(k->cub, x, k->infos);
		ft_calsidedist(k->cub);
		ft_dda(k->cub, k->infos);
		ft_perpwall_drawstart_end(k->cub, k->infos);
		ft_draw(k->cub, x, k->infos);
		x++;
	}
	mlx_put_image_to_window(k->cub->mlx, k->cub->win, k->cub->frame, 0, 0);
}
