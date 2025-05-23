/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:38:46 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 13:29:57 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	str = (char *)ft_safe_allocate(
			(size_t[2]){s1_len + 1, sizeof(char)},
			ALLOCATE, NULL, NULL);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_len + 1);
	return (str);
}
