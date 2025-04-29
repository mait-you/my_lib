/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:54:51 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 09:30:28 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putadress(unsigned long nb)
{
	int		re_value;
	char	*base;

	re_value = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		re_value += ft_putadress(nb / 16);
	re_value += ft_putchr(base[nb % 16]);
	return (re_value);
}
