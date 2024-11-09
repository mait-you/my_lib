/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:32:05 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/01 09:13:26 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr;

	if (!src && !dst)
		return (NULL);
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
