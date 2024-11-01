/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:33:41 by mait-you          #+#    #+#             */
/*   Updated: 2024/10/23 11:54:06 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;
	if (cc >= 'A' && cc <= 'Z')
		return (cc + ('a' - 'A'));
	return (cc);
}
