/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:28:42 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/17 19:18:54 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	int					l;
	char				*tmp;
	char				*ret;

	if (!s || !f)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	if (!(tmp = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	ret = tmp;
	while (*s)
	{
		*tmp++ = (*f)(i, *s++);
		i++;
	}
	*tmp = '\0';
	return (ret);
}
