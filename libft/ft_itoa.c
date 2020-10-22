/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:10:28 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/23 13:54:45 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long nbr)
{
	int		l;
	long	tmp;

	tmp = nbr;
	l = 0;
	if (tmp <= 0)
	{
		tmp *= -1;
		l++;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		l++;
	}
	return (l);
}

static long		ft_neg(char *nb, long n)
{
	if (n < 0)
	{
		n *= -1;
		nb[0] = '-';
	}
	return (n);
}

char			*ft_itoa(int n)
{
	long	nbr;
	int		i;
	char	*nb;
	char	*ret;

	nbr = n;
	i = ft_len(nbr);
	if (!(nb = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nbr = ft_neg(nb, nbr);
	ret = nb;
	nb += i - 1;
	while (nbr >= 10)
	{
		*nb = (nbr % 10) + '0';
		nb--;
		nbr /= 10;
	}
	if (nb != 0)
		*nb = (nbr % 10) + '0';
	ret[i] = '\0';
	return (ret);
}
