/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:32:52 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/15 16:39:14 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*tmp;

	tmp = lst;
	c = 0;
	while (tmp)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}
