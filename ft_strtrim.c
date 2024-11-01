/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:03:48 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 09:48:20 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 11:12:53 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static int	trim(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
=======
static int	trim(char const *s1, char const *set)
{
	while (*set)
	{
		if (*s1 == *set)
>>>>>>> Day 11
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
<<<<<<< HEAD
	char	*ptr;
	char	fc;
	char	lc;
	size_t	ptr_len;

	if (!s1 || !set)
		return (ft_strdup(""));
	fc = *s1;
	lc = *(s1 + ft_strlen(s1) - 1);
	if (trim(fc, set))
		s1++;
	ptr_len = ft_strlen(s1);
	if (trim(lc, set))
		ptr_len--;
	ptr = (char *)ft_calloc(ptr_len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ptr_len);
	return (ptr);
=======
	int		ptr_len;
	int		s_len;
	int		i;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(""));
	while (trim(s1, set))
		s1++;
	s_len = ft_strlen(s1);
	i = 0;
	while (trim(((s1 + s_len) - 1 - i), set))
		i++;
	ptr_len = s_len - i;
	return (ft_substr(s1, 0, ptr_len));
>>>>>>> Day 11
}
