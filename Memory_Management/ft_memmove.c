/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:32:05 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 09:32:17 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;

	if (!src && !dst)
		return (NULL);
	ptr = (char *)dst;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(ptr + len) = *(const char *)(src + len);
	}
	return (dst);
}