/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_allocate_cleanup.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:46:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 13:34:39 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_safe_allocate.h"

int	add_to_tracking(
	t_allocation *ptr_array, void *original_ptr, void *user_ptr, size_t *size)
{
	size_t	hash;
	int		i;

	i = 0;
	hash = hash_ptr(user_ptr);
	while (i < HASH_TABLE_SIZE)
	{
		if (ptr_array[hash].user_ptr == NULL)
		{
			ptr_array[hash].original_ptr = original_ptr;
			ptr_array[hash].user_ptr = user_ptr;
			if (size)
				ptr_array[hash].size = size[0] * size[1];
			return (SUCCESS);
		}
		hash = (hash + 1) % HASH_TABLE_SIZE;
		i++;
	}
	ft_putstr_fd_sa(ERR_ALLOC_TRACK_LIMIT, STDERR_FILENO);
	return (ERROR);
}

void	*free_one_memfen(t_allocation *ptr_array, const void *ptr)
{
	int		i;
	size_t	hash;
	void	*original_ptr;

	original_ptr = (void *)((unsigned char *)ptr - GUARD_SIZE);
	hash = hash_ptr(ptr);
	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		if (ptr_array[hash].original_ptr == original_ptr)
		{
			check_memfen(ptr_array[hash].user_ptr, ptr_array[hash].size);
			free(ptr_array[hash].original_ptr);
			return (ft_memset_sa(
				&ptr_array[hash], 0, sizeof(t_allocation)), NULL);
		}
		if (ptr_array[hash].original_ptr == NULL)
			break ;
		hash = (hash + 1) % HASH_TABLE_SIZE;
		i++;
	}
	ft_putstr_fd_sa(WARN_PTR_NOT_ALLOCATED, STDERR_FILENO);
	return (NULL);
}

void	*free_one(t_allocation *ptr_array, const void *ptr)
{
	int		i;
	size_t	hash;

	hash = hash_ptr(ptr);
	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		if (ptr_array[hash].user_ptr == ptr)
		{
			free(ptr_array[hash].user_ptr);
			ft_memset_sa(&ptr_array[hash], 0, sizeof(t_allocation));
			return (NULL);
		}
		if (ptr_array[hash].user_ptr == NULL)
			break ;
		hash = (hash + 1) % HASH_TABLE_SIZE;
		i++;
	}
	ft_putstr_fd_sa(WARN_PTR_NOT_ALLOCATED, STDERR_FILENO);
	return (NULL);
}

static void	*free_one_con(t_allocation *ptr_array, void **double_ptr)
{
	if (MEMORY_FENCING)
		free_one_memfen(ptr_array, double_ptr);
	else if (!MEMORY_FENCING)
		free_one(ptr_array, double_ptr);
	return (NULL);
}

void	*free_list(t_allocation *ptr_array, void **double_ptr, int count)
{
	int	i;

	i = -1;
	if (count == 0)
	{
		while (double_ptr && double_ptr[++i])
		{
			if (MEMORY_FENCING)
				double_ptr[i] = free_one_memfen(ptr_array, double_ptr[i]);
			else if (!MEMORY_FENCING)
				double_ptr[i] = free_one(ptr_array, double_ptr[i]);
		}
		return (free_one_con(ptr_array, double_ptr));
	}
	while (double_ptr && ++i < count)
	{
		if (MEMORY_FENCING)
			double_ptr[i] = free_one_memfen(ptr_array, double_ptr[i]);
		else if (!MEMORY_FENCING)
			double_ptr[i] = free_one(ptr_array, double_ptr[i]);
	}
	return (free_one_con(ptr_array, double_ptr));
}
