/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:34:00 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 09:54:47 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/10/31 11:01:09 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

<<<<<<< HEAD
	if (!src || !n)
		return (dst);
=======
	if (!src && !dst)
		return (0);
>>>>>>> Day 11
	i = 0;
	ptr = (unsigned char *)dst;
	while (i < n)
	{
<<<<<<< HEAD
		*(ptr + i) = *(const unsigned char *)(src + i);
=======
		*(ptr++) = *(const unsigned char *)(src++);
>>>>>>> Day 11
		i++;
	}
	return (dst);
}
