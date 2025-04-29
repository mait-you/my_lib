/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_allocate.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:44:47 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/26 15:23:17 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SAFE_ALLOCATE_H
# define FT_SAFE_ALLOCATE_H

/* Standard library includes */
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

/* ************************************************************************** */
/* 							Configuration Parameters                          */
/* ************************************************************************** */

/**
 * @brief Enable memory fencing to detect buffer overflows/underflows
 * Set to true to enable guard bytes around allocated memory
 */
# ifndef MEMORY_FENCING
#  define MEMORY_FENCING false
# endif

/**
 * @brief Size of the hash table for tracking allocations
 * Larger values reduce collision probability but increase memory usage
 */
# define HASH_TABLE_SIZE 2048

/**
 * @brief Size of guard regions in bytes
 * Used when MEMORY_FENCING is enabled
 */
# define GUARD_SIZE 8

/**
 * @brief Pattern used for guard bytes
 * Used to detect buffer overflow/underflow
 */
# define GUARD_PATTERN 0xAB

/* ************************************************************************** */
/* 							Status Codes and Messages                         */
/* ************************************************************************** */

/**
 * @brief Operation status codes
 */
# define SUCCESS 0
# define ERROR 1

/**
 * @brief Warning messages
 */
# define WARN_NEAR_ALLOC_LIMIT "\033[33mWarning: \033[0mnearing allocation \
limit\n"
# define WARN_BOTH_PTR "\033[33mWarning: \033[0mBoth ptr and double_ptr \
provided. Only ptr will be freed.\n"
# define WARN_FREE_NULL_PTR "\033[33mWarning: \033[0mattempt to free a NULL \
pointer\n"
# define WARN_PTR_NOT_ALLOCATED "\033[33mWarning: \033[0mpointer was not \
allocated by ft_safe_allocate so it cannot be freed using it\n"

/**
 * @brief Error messages
 */
# define ERR_ALLOC_TRACK_LIMIT "\033[31mError: \033[0mallocation tracking \
limit reached\n"
# define ERR_CORRUPTION_START "\033[31mError: \033[0mmemory corruption \
detected at START  guard byte of: 0x"
# define ERR_CORRUPTION_END "\033[31mError: \033[0mmemory corruption \
detected at END guard byte of: 0x"
# define ERR_MALLOC_FAILED "\033[31mError: \033[0mmemory allocation failed\n"

/* ************************************************************************** */
/* 							Data Structures                                   */
/* ************************************************************************** */

/**
 * @brief Forward declarations
 */
typedef struct s_allocation		t_allocation;
typedef enum e_action			t_action;

/**
 * @brief Structure to track memory allocations
 * 
 * @param original_ptr	Original allocated pointer (before guard bytes)
 * @param user_ptr		Pointer provided to user (after guard bytes)
 * @param size			Size of allocated memory (user portion only)
 */
struct s_allocation
{
	void	*original_ptr;
	void	*user_ptr;
	size_t	size;
};

/**
 * @brief Action enum for ft_safe_allocate function
 */
enum e_action
{
	ALLOCATE,			/* Allocate new memory */
	FREE_ALL,			/* Free all tracked allocations */
	FREE_ONE,			/* Free a specific allocation */
	GET_USAGE,			/* Get count of current allocations */
	REALLOC,			/* Reallocate existing memory */
	ADD_TO_TRACK,		/* Add externally allocated memory to tracking */
};

/* ************************************************************************** */
/* 							Function Prototypes                               */
/* ************************************************************************** */

/**
 * @brief Safe memory management function with multiple operations
 *
 * This function handles memory allocation, deallocation, and tracking with 
 * thread safety using a mutex. It can allocate new memory, free specific or all
 * allocations, get usage statistics, and reallocate memory.
 *
 * @param size Pointer to size info | interpretation depends on action:
 *        - For ALLOCATE/REALLOC: size[0]=count, size[1]=element size
 *        - For FREE_ONE: size[0]=element count of @double_ptr
 *        - For other actions: Can be NULL
 * @param action Operation to perform (ALLOCATE, FREE_ALL, FREE_ONE,
 *         GET_USAGE, REALLOC, ADD_TO_TRACK)
 * @param ptr Pointer to free or reallocate (for FREE_ONE, REALLOC)
 * @param double_ptr Array of pointers to free (optional with FREE_ONE)
 *
 * @return For ALLOCATE/REALLOC: Allocated pointer
 *         For GET_USAGE: Cast (void *)(uintptr_t) of allocation count
 *         For FREE_ONE/FREE_ALL: NULL
 *         On error: NULL
 */
void	*ft_safe_allocate(\
	size_t *size, t_action action, void *ptr, void **double_ptr);

/**
 * @brief Computes a hash value for a pointer
 *
 * This function generates a hash value for a pointer to be used as an index
 * in the allocation tracking hash table.
 *
 * @param ptr Pointer to hash
 *
 * @return Hash value modulo HASH_TABLE_SIZE as an index into the tracking array
 */
size_t	hash_ptr(const void *ptr);

/**
 *  Action functions
 */

/**
 * @brief Allocates memory and adds it to the tracking system
 *
 * This function allocates memory of the specified size and adds it to
 * the allocation tracking array. It handles memory fencing if enabled.
 *
 * @param size Pointer to size array: size[0]=count, size[1]=element size
 * @param ptr_array The allocation tracking array
 *
 * @return Pointer to the allocated memory, or NULL on failure
 */
void	*allocate_ptr(size_t *size, t_allocation *ptr_array);

/**
 * @brief Frees all tracked allocations
 *
 * This function iterates through the tracking array and frees all
 * non-NULL pointers that have been allocated by the system.
 *
 * @param ptr_array The allocation tracking array
 *
 * @return Always returns NULL to indicate all memory has been freed
 */
void	*free_all(t_allocation *ptr_array);

/**
 * @brief Handles specific free operations based on provided parameters
 *
 * This function serves as a router for different types of free operations
 * based on the parameters provided. It can free a single pointer or an array.
 *
 * @param ptr_array The allocation tracking array
 * @param ptr The pointer to free
 * @param double_ptr Optional array of pointers to free
 * @param size Optional size information
 *
 * @return Always returns NULL to indicate the memory has been freed
 */
void	*free_specific(\
	t_allocation *ptr_array, const void *ptr, void **double_ptr, size_t *size);

/**
 * @brief Gets the number of active allocations in the tracking system
 *
 * This function counts the number of non-NULL pointers in the tracking array
 * to determine how many active allocations are being tracked.
 *
 * @param ptr_array The allocation tracking array
 *
 * @return Number of active allocations
 */
int		get_allocation_count(t_allocation *ptr_array);

/**
 * @brief Reallocates memory while maintaining tracking information
 *
 * This function changes the size of a previously allocated memory block
 * while preserving its contents and updating the tracking information.
 *
 * @param size Pointer to size array: size[0]=count, size[1]=element size
 * @param ptr_array The allocation tracking array
 * @param ptr The pointer to reallocate
 *
 * @return Pointer to the reallocated memory, or NULL on failure
 */
void	*realloc_ptr(\
	size_t *size, t_allocation *ptr_array, void *ptr, t_action action);

/**
 * @brief Adds externally allocated memory to the tracking system
 *
 * This function allows adding memory that was allocated outside the
 * ft_safe_allocate system to be tracked and safely freed later.
 *
 * @param ptr_array The allocation tracking array
 * @param original_ptr The original pointer from malloc/calloc
 * @param user_ptr The user-facing pointer (same as original_ptr if no fencing)
 * @param size Pointer to the size of the allocated memory
 *
 * @return SUCCESS if successfully added, ERROR otherwise
 */
int		add_to_tracking(\
	t_allocation *ptr_array, void *original_ptr, void *user_ptr, size_t *size);

/**
 *  	cleanup functions
 */

/**
 * @brief Frees an array of pointers tracked in the allocation system
 *
 * This function frees a list of pointers stored in a double pointer array.
 * It will free 'count' number of pointers from the array.
 *
 * @param ptr_array The allocation tracking array
 * @param double_ptr Array of pointers to free
 * @param count Number of pointers to free from the array
 *
 * @return Always returns NULL to indicate the memory has been freed
 */
void	*free_list(t_allocation *ptr_array, void **double_ptr, int count);

/**
 * @brief Frees a single pointer tracked in the allocation system
 *
 * This function frees a pointer that was allocated without memory fencing.
 * It searches for the pointer in the tracking array and frees it if found.
 *
 * @param ptr_array The allocation tracking array
 * @param ptr The pointer to free
 *
 * @return Always returns NULL to indicate the memory has been freed
 */
void	*free_one(t_allocation *ptr_array, const void *ptr);

/**
 * @brief Frees a single pointer with memory fencing enabled
 *
 * This function frees a pointer that was allocated with memory fencing.
 * It checks guard bytes for corruption before freeing the memory.
 *
 * @param ptr_array The allocation tracking array
 * @param ptr The user pointer to free (points after guard bytes)
 *
 * @return Always returns NULL to indicate the memory has been freed
 */
void	*free_one_memfen(t_allocation *ptr_array, const void *ptr);

/**
 * 		Memory fencing functions
 */

/**
 * @brief Sets up memory fencing around an allocated block
 *
 * This function adds guard bytes at the beginning and end of an allocated
 * memory block to detect buffer overflows and underflows.
 *
 * @param ptr The original allocated pointer
 * @param total_size Total size including user data and guard regions
 *
 * @return Pointer to the user data portion (after initial guard bytes)
 */
void	*setup_memfen(void *ptr, size_t total_size);

/**
 * @brief Checks memory fencing guard bytes for corruption
 *
 * This function verifies that guard bytes at the beginning and end of
 * an allocated block haven't been modified, indicating memory corruption.
 *
 * @param user_ptr Pointer to the user data portion
 * @param user_size Size of the user data portion
 *
 * @return SUCCESS if no corruption detected, ERROR otherwise
 */
int		check_memfen(void *user_ptr, size_t user_size);

/**
 * @brief Utility functions
 */
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_puthex_fd(unsigned long n, int fd);

#endif /* FT_SAFE_ALLOCATE_H */
