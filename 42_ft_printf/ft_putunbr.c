/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:23:51 by mait-you          #+#    #+#             */
/*   Updated: 2025/04/29 09:30:39 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	re_value;

	re_value = 0;
	if (nb >= 10)
	{
		re_value += ft_putunbr(nb / 10);
		re_value += ft_putunbr(nb % 10);
	}
	else
		re_value += ft_putchr(nb + '0');
	return (re_value);
}
