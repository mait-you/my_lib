/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:00:34 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/01 12:44:02 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
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
}
