/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:55:08 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/09 14:46:38 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	l;

	l = ft_strlen(string);
	while (*string)
		string++;
	while (l >= 0)
	{
		if (*string == c)
			return ((char *)string);
		string--;
		l--;
	}
	return (NULL);
}
