/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:58:35 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/01 11:23:12 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	key;

	count = 0;
	key = 1;
	while (*s)
	{
		if (*s != c && key)
		{
			count++;
			key = !key;
		}
		if (*s == c && !key)
			key = !key;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	ptr = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!ft_strchr(s, c))
			len = ft_strlen(s);
		else
			len = ft_strchr(s, c) - s;
		*(ptr + i++) = ft_substr(s, 0, len);
		s += len;
	}
	*(ptr + i) = NULL;
	return (ptr);
}
