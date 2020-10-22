/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:09:40 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/09 10:42:08 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int count;
	unsigned int j;

	j = 0;
	i = 0;
	count = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	count = i + j;
	if (i >= size)
		return (count - i + size);
	j = 0;
	while (*src != 0 && i < size - 1)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (count);
}
