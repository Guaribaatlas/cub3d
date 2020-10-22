/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:08:53 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/08 17:52:36 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		if (*(unsigned char*)dest++ == (unsigned char)c)
			return (dest);
		src++;
		n--;
	}
	return (NULL);
}
