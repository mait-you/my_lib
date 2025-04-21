/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_allocate_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:25:38 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/21 13:23:22 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Adds a newly allocated pointer to the tracking array.
 * 
 * @param ptr_array The tracking array to store allocation info.
 * @param original_ptr The original pointer, if any (used for debugging or
 *        fencing).
 * @param user_ptr The actual user-accessible pointer to be tracked.
 * @param size An array of two size_t values: count and size of each element.
 * 
 * @return int SUCCESS if added, ERROR if the tracking array is full.
 */
int	add_to_tracking(
	t_allocation *ptr_array,
	void *original_ptr,
	void *user_ptr,
	size_t size[2])
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
			ptr_array[hash].size = size[0] * size[1];
			return (SUCCESS);
		}
		hash = (hash + 1) % HASH_TABLE_SIZE;
		i++;
	}
	ft_putendl_fd(ERR_ALLOC_TRACK_LIMIT, STDERR_FILENO);
	return (ERROR);
}

/**
 * @brief Fills a block of memory with a specific byte value.
 * 
 * @param b Pointer to the block of memory to fill.
 * @param c The byte value to set.
 * @param len Number of bytes to set.
 * 
 * @return void* The original pointer 'b'.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len-- > 0)
		*(ptr++) = (unsigned char)c;
	return (b);
}

/**
 * @brief Allocates and zeroes memory for an array of elements.
 * 
 * @param count Number of elements to allocate.
 * @param size Size of each element.
 * 
 * @return void* Pointer to the allocated and zero-initialized memory block,
 *         or NULL on failure or overflow.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

/**
 * @brief Copies 'n' bytes from source to destination.
 * 
 * @param dst Destination buffer.
 * @param src Source buffer.
 * @param n Number of bytes to copy.
 * 
 * @return void* Pointer to the destination buffer.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*ptr;

	if (!src && !dst)
		return (0);
	i = 0;
	ptr = (char *)dst;
	while (i < n)
	{
		*(ptr++) = *((const char *)src++);
		i++;
	}
	return (dst);
}

/**
 * @brief Writes a string followed by a newline to the given file descriptor.
 * 
 * @param s The string to write.
 * @param fd The file descriptor (e.g., 1 for stdout, 2 for stderr).
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd == -1)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
