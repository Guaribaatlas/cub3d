/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:01:04 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/09 13:54:57 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int count;
	int k;
	int j;

	count = ft_strlen(needle);
	if (count == 0)
		return ((char *)haystack);
	while (*haystack && len != 0)
	{
		k = 0;
		j = len;
		while ((haystack[k] == needle[k]) && k < count && j-- > 0)
			k++;
		if (k == count)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
