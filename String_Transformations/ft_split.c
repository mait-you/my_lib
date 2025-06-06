/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:58:35 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 10:39:43 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
			key = 0;
		}
		else if (*s == c)
			key = 1;
		s++;
	}
	return (count);
}

static char	**x(char const *s, char c, char	**ptr)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			ptr[i] = ft_substr(s, 0, len);
			if (!ptr[i])
				return (ft_safe_allocate(
						NULL, FREE_ONE, NULL, (void **)ptr));
			i++;
			s += len;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)ft_safe_allocate(
			(size_t[2]){count_words(s, c) + 1, sizeof(char *)},
			ALLOCATE, NULL, NULL);
	if (!ptr)
		return (NULL);
	return (x(s, c, ptr));
}
