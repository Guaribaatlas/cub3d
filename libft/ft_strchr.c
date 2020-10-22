/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:19:13 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/09 12:16:49 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*(char*)string == (char)c)
			return ((char *)string);
		string++;
	}
	if ((char)c == 0)
		return ((char *)string);
	return (NULL);
}
