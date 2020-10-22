/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dplcmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:52:01 by jehaenec          #+#    #+#             */
/*   Updated: 2020/09/24 10:54:02 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
int		key_hook(int keycode, t_hook *k)
{
	double old_dir_x;
	double old_plane_x;

	if (keycode == 17)
	{
		if (k->cub->textured == 0)
			k->cub->textured = 1;
		else
			k->cub->textured = 0;
		ft_rc(k);
	}
	if (keycode == 53)
	{
		mlx_destroy_image(k->cub->mlx, k->cub->frame);
		mlx_destroy_window(k->cub->mlx, k->cub->win);
		exit(0);
	}
	if (keycode == 13)
	{
     if (k->infos->map[(int)(k->cub->pos[Y] + k->cub->dir[Y] *
     k->cub->movespeed)][(int)k->cub->pos[X]] != '1')
		 k->cub->pos[Y] += k->cub->dir[Y] * k->cub->movespeed;
	 if (k->infos->map[(int)k->cub->pos[Y]][(int)(k->cub->pos[X] +
	 k->cub->dir[X] * k->cub->movespeed)] != '1')
		 k->cub->pos[X] += k->cub->dir[X] * k->cub->movespeed;
	 ft_rc(k);
	 return(0);
	}
	if (keycode == 1)
	{
	 if(k->infos->map[(int)(k->cub->pos[Y] - k->cub->dir[Y] *
	 k->cub->movespeed)][(int)k->cub->pos[X]] != '1')
		 k->cub->pos[Y] -= k->cub->dir[Y] * k->cub->movespeed;
      if(k->infos->map[(int)k->cub->pos[Y]][(int)(k->cub->pos[X] -
      k->cub->dir[X] * k->cub->movespeed)] != '1')
		  k->cub->pos[X] -= k->cub->dir[X] * k->cub->movespeed;
	  ft_rc(k);
	  return (0);
	}
	if (keycode == 2)
	{
		if (k->infos->map[(int)(k->cub->pos[Y] + k->cub->dir[X] *
		k->cub->movespeed)][(int)k->cub->pos[X]] != '1')
			k->cub->pos[Y] += k->cub->dir[X] * k->cub->movespeed;
		if (k->infos->map[(int)k->cub->pos[Y]][(int)(k->cub->pos[X] -
		k->cub->dir[Y] * k->cub->movespeed)] != '1')
			k->cub->pos[X] -= k->cub->dir[Y] * k->cub->movespeed;
		ft_rc(k);
		return(0);
	}
	if (keycode == 0)
	{
		if (k->infos->map[(int) (k->cub->pos[Y] - k->cub->dir[X]
		*k->cub->movespeed)][(int) k->cub->pos[X]] != '1')
		{
			k->cub->pos[Y] -= k->cub->dir[X] * k->cub->movespeed;
		}
		if (k->infos->map[(int)k->cub->pos[Y]][(int)(k->cub->pos[X]
		+ k->cub->dir[Y] * k->cub->movespeed)] != '1')
		{
			k->cub->pos[X] += k->cub->dir[Y] * k->cub->movespeed;
		}
		ft_rc(k);
		return (0);
	}
	if (keycode == 123)
	{
		old_dir_x = k->cub->dir[X];
		k->cub->dir[X] = k->cub->dir[X] * cos(-k->cub->rotspeed) - k->cub->dir[Y] * sin(-k->cub->rotspeed);
		k->cub->dir[Y] = old_dir_x * sin(-k->cub->rotspeed) + k->cub->dir[Y] * cos(-k->cub->rotspeed);
		old_plane_x = k->cub->plane[X];
		k->cub->plane[X] = k->cub->plane[X] * cos(-k->cub->rotspeed) - k->cub->plane[Y] * sin(-k->cub->rotspeed);
		k->cub->plane[Y] = old_plane_x * sin(-k->cub->rotspeed) + k->cub->plane[Y] * cos(-k->cub->rotspeed);
		ft_rc(k);
		return(0);
	}
	 if (keycode == 124)
	{
		old_dir_x = k->cub->dir[X];
		k->cub->dir[X] = k->cub->dir[X] * cos(k->cub->rotspeed) - k->cub->dir[Y] * sin(k->cub->rotspeed);
		k->cub->dir[Y] = old_dir_x * sin (k->cub->rotspeed) + k->cub->dir[Y] * cos(k->cub->rotspeed);
		old_plane_x = k->cub->plane[X];
		k->cub->plane[X] = k->cub->plane[X] * cos(k->cub->rotspeed) - k->cub->plane[Y] * sin(k->cub->rotspeed);
		k->cub->plane[Y] = old_plane_x * sin(k->cub->rotspeed) + k->cub->plane[Y] * cos(k->cub->rotspeed);
		ft_rc(k);
		return(0);
	}
	return (0);
}

