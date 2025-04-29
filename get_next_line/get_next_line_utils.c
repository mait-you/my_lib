/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:24:59 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 10:33:44 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen_gln(char *str)
{
	int	l;

	l = 0;
	while (str && *str++)
		l++;
	return (l);
}

char	*ft_strjoin_gln(char *s1, char *s2)
{
	char	*r;
	char	*ptr;

	ptr = (char *)ft_safe_allocate(\
			(size_t[2]){ft_strlen_gln(s1) + ft_strlen_gln(s2) + 1,
			sizeof(char)},
			ALLOCATE,
			NULL,
			NULL);
	if (!ptr)
		return (NULL);
	r = ptr;
	while (s1 && *s1)
		*ptr++ = *s1++;
	while (s2 && *s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (r);
}

int	is_there_any_newline(char *backup_line)
{
	while (backup_line && *backup_line)
	{
		if (*backup_line == '\n')
			return (1);
		backup_line++;
	}
	return (0);
}
