/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:34:00 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 09:32:15 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
		*(ptr++) = *(const char *)(src++);
		i++;
	}
	return (dst);
}
