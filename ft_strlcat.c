/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:17:10 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/01 12:38:18 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
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
	return (dst_len + src_len);
}
