/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:24:59 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/23 12:06:11 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_strlen_gln(char *str)
{
    int l = 0;

    while (str && *str++)
        l++;
    return (l);
}

char *ft_strjoin_gln(char *s1, char *s2)
{
    char *r;
    char *ptr;
    ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
