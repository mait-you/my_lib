/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:58:42 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 09:28:02 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 10:28:03 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

<<<<<<< HEAD
	if (!count || !size)
		return (malloc(0));
=======
>>>>>>> Day 11
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
