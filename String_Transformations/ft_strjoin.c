/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:19:57 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/19 10:15:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (!s2)
		s2_len = 0;
	else
		s2_len = ft_strlen(s2);
	ptr = (char *)ft_safe_calloc(
		(size_t){s1_len + s2_len + 1, sizeof(char)}, ALLOCATE, NULL);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	return (ptr);
}
