/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:32:05 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 09:31:17 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 09:13:26 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;

<<<<<<< HEAD
	if (!len || !src || !dst)
		return (dst);
=======
	if (!src && !dst)
		return (NULL);
>>>>>>> Day 11
	ptr = (unsigned char *)dst;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(ptr + len) = *(const unsigned char *)(src + len);
	}
	return (dst);
}
