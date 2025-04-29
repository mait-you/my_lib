/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:38:17 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 10:30:10 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *s)
{
	int		re_value;

	if (!s)
		s = "(null)";
	re_value = 0;
	while (*s)
	{
		re_value += ft_putchr(*s);
		s++;
	}
	return (re_value);
}
