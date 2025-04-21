/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:58:35 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/21 12:49:46 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

static char	**free_memory(char **ptr, int i)
{
	int	j;

	j = 0;
	while (j < i)
		ft_safe_allocate(0, FREE_ONE, ptr[j++]);
	ft_safe_allocate(0, FREE_ONE, ptr);
	return (NULL);
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
				return (free_memory(ptr, i));
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
	ptr =(char **)ft_safe_allocate(
		(size_t[2]){count_words(s, c) + 1, sizeof(char *)}, ALLOCATE, NULL);
	if (!ptr)
		return (NULL);
	return (x(s, c, ptr));
}
