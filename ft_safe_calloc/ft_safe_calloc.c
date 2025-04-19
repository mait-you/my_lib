/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:35:29 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/19 09:50:41 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	*free_specific(void **ptr_array, void *to_delete)
{
	int	i;

	if (!to_delete)
		return (NULL);
	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (ptr_array[i] == to_delete)
		{
			free(ptr_array[i]);
			ptr_array[i] = NULL;
			return (NULL);
		}
		i++;
	}
	free(to_delete);
	return (NULL);
}

static void	*free_all(void **ptr_array)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (ptr_array[i])
		{
			free(ptr_array[i]);
			ptr_array[i] = NULL;
		}
		i++;
	}
	return (NULL);
}

static int	add_to_tracking(void **ptr_array, void *ptr)
{
	int	i;

	if (!ptr)
		return (0);
	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (ptr_array[i] == NULL)
		{
			ptr_array[i] = ptr;
			return (1);
		}
		i++;
	}
	return (0);
}

static void	*allocate_ptr(size_t size[2], void **ptr_array)
{
	void	*ptr;

	ptr = ft_calloc(size[0], size[1]);
	if (!ptr)
		free_all(ptr_array);
	if (!add_to_tracking(ptr_array, ptr))
	{
		free(ptr);
		free_all(ptr_array);
	}
	return (ptr);
}

void	*ft_safe_calloc(size_t size[2], t_keys key, void *to_delete)
{
	static void	*ptr_array[MAX_ALLOCATIONS] = {NULL};
	void		*ptr;

	ptr = NULL;
	if (key == ALLOCATE)
		ptr = allocate_ptr(size, ptr_array);
	else if (key == FREE_ALL)
		ptr = free_all(ptr_array);
	else if (key == FREE_ONE)
		ptr = free_specific(ptr_array, to_delete);
	return (ptr);
}
