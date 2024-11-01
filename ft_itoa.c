/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:17:14 by mait-you          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/25 09:11:06 by mait-you         ###   ########.fr       */
=======
/*   Updated: 2024/11/01 11:26:35 by mait-you         ###   ########.fr       */
>>>>>>> Day 11
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long int n)
{
	int	l;

	l = 1;
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 1)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static void	ft_putnb(char *s, int n)
{
	if (n > 9)
		ft_putnb(s - 1, n / 10);
	*s = '0' + (n % 10);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	char		*str;

	nb = n;
	len = n_len(nb);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		*str = '-';
		nb = -nb;
	}
	ft_putnb(str + len - 1, nb);
<<<<<<< HEAD
	*(str + len) = '\0';
=======
	*(str + len) = 0;
>>>>>>> Day 11
	return (str);
}
