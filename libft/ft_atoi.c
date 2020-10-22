/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:41:22 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/27 20:36:41 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int	ft_verif(const char *str, int m)
{
	if (ft_len(str) >= 19 &&
		ft_strncmp(str, "9223372036854775807", 20) > 0 && m == 1)
		return (-1);
	else if (ft_len(str) >= 19 &&
			ft_strncmp(str, "9223372036854775808", 20) > 0 && m == -1)
		return (0);
	return (1);
}

int			ft_atoi(const char *str)
{
	int			m;
	long long	nb;
	int			r;

	nb = 0;
	m = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' ||
			*str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m = -1;
		str++;
	}
	r = ft_verif(str, m);
	if (r != 1)
		return (r);
	while (*str >= '0' && *str <= '9')
	{
		nb = ((nb * 10) + *str) - 48;
		str++;
	}
	return (nb * m);
}
