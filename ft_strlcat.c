/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:17:10 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 09:55:02 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 12:38:18 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
<<<<<<< HEAD
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	if (dstsize <= src_len)
		return (dstsize + src_len);
	i = 0;
	while (src && i < (dstsize - dst_len - 1))
	{
		*(dst + dst_len + i) = *(src++);
		i++;
	}
	*(dst + dst_len + i) = '\0';
=======
	unsigned int	dst_len;
	unsigned int	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	if (dstsize - dst_len < src_len)
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		*(dst + dstsize - 1) = 0;
	}
	else
		ft_memcpy(dst + dst_len, src, src_len + 1);
>>>>>>> Day 11
	return (dst_len + src_len);
}
