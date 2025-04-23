/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:48:48 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/23 12:01:00 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	copy_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > (s_len - start))
		copy_len = s_len - start;
	else
		copy_len = len;
	substr = (char *)ft_safe_allocate(
		(size_t[2]){copy_len + 1, sizeof(char)}, ALLOCATE, NULL);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, copy_len);
	substr[copy_len] = '\0';
	return (substr);
}
