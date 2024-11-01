/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mait-you <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:45:37 by mait-you          #+#    #+#             */
/*   Updated: 2024/10/22 19:46:01 by mait-you         ###   ########.fr       */
=======
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:45:37 by mait-you          #+#    #+#             */
/*   Updated: 2024/10/29 10:25:49 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;

	cc = (unsigned char)c;
	ss = (unsigned char *)s;
<<<<<<< HEAD
	while (*ss && n--)
=======
	while (n--)
>>>>>>> Day 11
	{
		if (*ss == cc)
			return ((void *)s);
		s++;
		ss++;
	}
<<<<<<< HEAD
	if (cc == '\0')
		return ((void *)s);
=======
>>>>>>> Day 11
	return (NULL);
}
