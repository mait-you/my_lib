/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_allocate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:46:19 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/21 13:23:19 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief This function converts the pointer to a numeric value (`uintptr_t`),
 *        then calculates the remainder when divided by `HASH_TABLE_SIZE` to 
 *        determine the appropriate location for the pointer in the hash table.
 * 
 * @param ptr The pointer whose hash value is to be computed.
 * @return size_t The hash value of the pointer, which is used to determine 
 *        its position in the hash table.
 */
size_t	hash_ptr(const void *ptr)
{
	return ((uintptr_t)ptr % HASH_TABLE_SIZE);
}

/**
 * @brief A safe memory management function that handles multiple actions such
 * 	      as:
 *        - Memory allocation (ALLOCATE)
 *        - Freeing all tracked allocations (FREE_ALL)
 *        - Freeing a specific allocation (FREE_ONE)
 *        - Reallocating an existing allocation (REALLOC)
 *        - Getting the current number of active allocations (GET_USAGE)
 * 
 *        It uses a static tracking array to store allocated pointers along
 *        with metadata, and it protects operations with a mutex to ensure 
 *        thread safety.
 * 
 * @param size An array of two size_t values: (size[2]){count, size}
 *        - size[0]: Number of elements to allocate.
 *        - size[1]: Size of each element.
 *        This parameter is only used in ALLOCATE and REALLOC actions.
 * 
 * @param action The action to be performed. It must be one of:
 *        - ALLOCATE: Allocate new memory.
 *        - FREE_ALL: Free all tracked pointers.
 *        - FREE_ONE: Free a specific pointer.
 *        - GET_USAGE: Return the number of currently tracked allocations.
 *        you have to cast on (int)(uintptr_t)
 *        - REALLOC: Reallocate an existing pointer.
 * 
 * @param ptr The pointer to be freed or reallocated. Used with FREE_ONE
 *        and REALLOC.
 * 
 * @return void* 
 *        - If action is ALLOCATE or REALLOC: returns the newly allocated
 *        memory pointer.
 *        - If action is GET_USAGE: returns the current number of active 
 *        allocations casted to a void*.
 *        - For FREE_ONE and FREE_ALL: always returns NULL.
 *        - If an error occurs (e.g., allocation failure), returns NULL.
 */
void	*ft_safe_allocate(size_t size[2], t_action action, void *ptr)
{
	static t_allocation		ptr_array[HASH_TABLE_SIZE];
	static pthread_mutex_t	init_mutex = PTHREAD_MUTEX_INITIALIZER;
	void					*user_ptr;

	pthread_mutex_lock(&init_mutex);
	user_ptr = NULL;
	if (action == ALLOCATE)
		user_ptr = allocate_ptr(size, ptr_array);
	else if (action == FREE_ALL)
		user_ptr = free_all(ptr_array);
	else if (action == FREE_ONE)
		user_ptr = free_specific(ptr_array, ptr);
	else if (action == GET_USAGE)
		user_ptr = (void *)(uintptr_t)get_allocation_count(ptr_array);
	else if (action == REALLOC)
		user_ptr = realloc_ptr(size, ptr_array, ptr);
	pthread_mutex_unlock(&init_mutex);
	return (user_ptr);
}
