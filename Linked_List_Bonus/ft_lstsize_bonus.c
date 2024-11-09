/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:52:07 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/08 18:17:08 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		l;

	if (!lst)
		return (0);
	current = lst;
	l = 0;
	while (current)
	{
		l++;
		current = current->next;
	}
	return (l);
}
