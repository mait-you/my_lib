/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_allocate_action.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:46:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/21 13:23:24 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Reallocates memory for a given pointer by allocating new memory,
 *        copying the old data, and freeing the old pointer.
 * 
 * @param size An array of two size_t values representing the number of elements
 *             and size of each element.
 * @param ptr_array The tracking array holding allocated memory blocks.
 * @param ptr The pointer to be reallocated.
 * 
 * @return void* A new memory pointer on success, NULL on failure.
 */
void	*realloc_ptr(size_t size[2], t_allocation *ptr_array, void *ptr)
{
	void	*new_ptr;

	new_ptr = allocate_ptr(size, ptr_array);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size[0] * size[1]);
		free_specific(ptr_array, ptr);
	}
	return (new_ptr);
}

/**
 * @brief Returns the number of active (non-NULL) allocations in the tracking
 *        array.
 * 
 * @param ptr_array The tracking array holding allocated memory blocks.
 * 
 * @return int The number of active allocations.
 */
int	get_allocation_count(t_allocation *ptr_array)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		if (ptr_array[i].user_ptr != NULL)
			count++;
		i++;
	}
	if (count > HASH_TABLE_SIZE * 0.9)
		ft_putendl_fd(WARN_NEAR_ALLOC_LIMIT, STDOUT_FILENO);
	return (count);
}

/**
 * @brief Frees a specific pointer from the tracking array. If the pointer is
 *        not found in the array, it frees it directly.
 * 
 * @param ptr_array The tracking array holding allocated memory blocks.
 * @param ptr The pointer to be freed.
 * 
 * @return void* Always returns NULL.
 */
void	*free_specific(t_allocation *ptr_array, const void *ptr)
{
	int		i;
	size_t	hash;

	if (!ptr)
		return (ft_putendl_fd(WARN_FREE_NULL_PTR, STDERR_FILENO), NULL);
	if (MEMORY_FENCING)
		return (free_specific_memory_fencing(ptr_array, ptr));
	i = 0;
	hash = hash_ptr(ptr);
	while (i < HASH_TABLE_SIZE)
	{
		if (ptr_array[hash].user_ptr == ptr)
		{
			free(ptr_array[hash].user_ptr);
			ft_memset(&ptr_array[hash], 0, sizeof(t_allocation));
			return (NULL);
		}
		if (ptr_array[hash].user_ptr == NULL)
			break ;
		hash = (hash + 1) % HASH_TABLE_SIZE;
		i++;
	}
	free((void *)ptr);
	ft_putendl_fd(WARN_PTR_NOT_ALLOCATED, STDERR_FILENO);
	return (NULL);
}

/**
 * @brief Frees all memory blocks stored in the tracking array and resets each
 *        slot.
 * 
 * @param ptr_array The tracking array holding allocated memory blocks.
 * 
 * @return void* Always returns NULL.
 */
void	*free_all(t_allocation *ptr_array)
{
	int	i;

	if (MEMORY_FENCING)
		return (free_all_memory_fencing(ptr_array));
	i = 0;
	while (i < HASH_TABLE_SIZE)
	{
		if (ptr_array[i].user_ptr)
		{
			free(ptr_array[i].user_ptr);
			ft_memset(&ptr_array[i], 0, sizeof(t_allocation));
		}
		i++;
	}
	return (NULL);
}

/**
 * @brief Allocates memory using ft_calloc and adds it to the tracking array.
 *        If allocation fails or tracking fails, all memory is freed.
 * 
 * @param size An array of two size_t values representing the number of elements
 *             and size of each element.
 * @param ptr_array The tracking array to store the allocation information.
 * 
 * @return void* The allocated memory pointer on success, NULL on failure.
 */
void	*allocate_ptr(size_t size[2], t_allocation *ptr_array)
{
	void	*user_ptr;

	if (MEMORY_FENCING)
		return (allocate_ptr_memory_fencing(size, ptr_array));
	user_ptr = ft_calloc(size[0], size[1]);
	if (!user_ptr)
	{
		free_all(ptr_array);
		return (NULL);
	}
	if (add_to_tracking(ptr_array, NULL, user_ptr, size) == ERROR)
	{
		free(user_ptr);
		free_all(ptr_array);
		return (NULL);
	}
	return (user_ptr);
}
