/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehaenec <jehaenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:08:38 by jehaenec          #+#    #+#             */
/*   Updated: 2019/10/27 20:24:10 by jehaenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*beg;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		beg = tmp->next;
		(*del)(tmp->content);
		free(tmp);
		tmp = beg;
	}
	*lst = NULL;
}
