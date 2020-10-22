/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:08:24 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/24 15:02:32 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		n;
	void	*m;

	n = count * size;
	if (!(m = (void *)malloc(n)))
		return (0);
	ft_bzero(m, n);
	return (m);
}
