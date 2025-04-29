/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:45:37 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 09:32:08 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	unsigned char		cc;

	cc = (unsigned char)c;
	ss = (const unsigned char *)s;
	while (n--)
	{
		if (*ss == cc)
			return ((void *)s);
		s++;
		ss++;
	}
	return (NULL);
}
