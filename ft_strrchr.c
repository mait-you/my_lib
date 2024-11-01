/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:00:34 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 09:38:57 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 12:44:02 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
<<<<<<< HEAD
	unsigned char	cc;
	size_t			s_len;

	cc = (unsigned char)c;
	s_len = ft_strlen(s);
	if (!cc)
		return ((char *)(s + s_len));
	while (s_len--)
	{
		if (s[s_len] == cc)
			return ((char *)(&s[s_len]));
	}
	return (NULL);
=======
	unsigned int	i;
	char			*res;
	char			cc;

	cc = (char) c;
	res = NULL;
	i = 0;
	while (*s)
	{
		if (*s == cc)
			res = (char *)s;
		s++;
	}
	if (*s == c)
		res = (char *)s;
	return (res);
>>>>>>> Day 11
}
