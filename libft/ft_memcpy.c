/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:02:58 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/10 14:41:20 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *i;

	if ((!dest && !src) || dest == src)
		return (NULL);
	i = (char *)dest;
	while (n)
	{
		*i = *(char*)src;
		i++;
		src++;
		n--;
	}
	return (dest);
}
