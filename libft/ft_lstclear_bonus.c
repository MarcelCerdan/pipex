/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthibaul <mthibaul@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:21 by mthibaul          #+#    #+#             */
/*   Updated: 2022/11/18 11:20:40 by mthibaul         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;

	if (!lst || *lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		elem = *lst;
		*lst = elem->next;
		ft_lstdelone(elem, del);
	}
}
