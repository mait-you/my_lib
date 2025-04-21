/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:48:48 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/21 12:50:21 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > (s_len - start))
		substr_len = (s_len - start) + 1;
	else
		substr_len = len + 1;
	substr = (char *)ft_safe_allocate(
		(size_t[2]){substr_len, sizeof(char)}, ALLOCATE, NULL);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, substr_len);
	return (substr);
}
