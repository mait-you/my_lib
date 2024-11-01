/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:59:56 by mait-you          #+#    #+#             */
/*   Updated: 2024/10/30 08:43:54 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lit;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lit = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lit, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lit, new_node);
		lst = lst->next;
	}
	return (new_lit);
}
