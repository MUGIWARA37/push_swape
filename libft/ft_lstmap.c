/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhlou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:07:41 by rhlou             #+#    #+#             */
/*   Updated: 2026/01/24 15:04:13 by rhlou            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*begin;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	begin = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!new_lst)
			ft_lstclear(&new_lst, del);
		ft_lstadd_back(&begin, new_lst);
		lst = lst->next;
	}
	return (begin);
}
