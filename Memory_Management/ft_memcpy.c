/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:34:00 by mait-you          #+#    #+#             */
/*   Updated: 2024/10/31 11:01:09 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!src && !dst)
		return (0);
	i = 0;
	ptr = (unsigned char *)dst;
	while (i < n)
	{
		*(ptr++) = *(const unsigned char *)(src++);
		i++;
	}
	return (dst);
}
