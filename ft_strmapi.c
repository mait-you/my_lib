/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:38:31 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 11:13:55 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 11:42:03 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
<<<<<<< HEAD
	int		i;
	char	*ptr;
=======
	unsigned int	i;
	char			*ptr;
>>>>>>> Day 11

	ptr = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
<<<<<<< HEAD
		ptr[i] = f(i, s[i]);
		i++;
	}
=======
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
>>>>>>> Day 11
	return (ptr);
}
