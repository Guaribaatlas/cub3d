/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:11:07 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/27 20:25:06 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int		i;

	if (!src || !dest)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(src);
	while (--size && *src)
		*dest++ = *src++;
	*dest = 0;
	return (i);
}
