/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:48:48 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/24 09:01:20 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 10:44:22 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;

<<<<<<< HEAD
	if (!s || !len)
=======
	if (!s)
>>>>>>> Day 11
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
<<<<<<< HEAD
	if (len > (s_len + start))
=======
	if (len > (s_len - start))
>>>>>>> Day 11
		substr_len = (s_len - start) + 1;
	else
		substr_len = len + 1;
	substr = (char *)ft_calloc(substr_len, sizeof(char));
	if (!substr)
		return (NULL);
<<<<<<< HEAD
	ft_strlcpy(substr, s + start, len + 1);
=======
	ft_strlcpy(substr, s + start, substr_len);
>>>>>>> Day 11
	return (substr);
}
