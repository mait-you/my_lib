/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:12:59 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/08 19:22:14 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	overflow_handle(long r, int s, const char *str)
{
	if (r > (9223372036854775807 / 10) || (r == (9223372036854775807 / 10) \
		&& (*str - '0') > (9223372036854775807 % 10)))
	{
		if (s == -1)
			return (0);
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int				overflow_check;
	int				i;
	long			r;
	int				s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflow_check = overflow_handle(r, s, &str[i]);
		if (overflow_check != 1)
			return (overflow_check);
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(s * r));
}
