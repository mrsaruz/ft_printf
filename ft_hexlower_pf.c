/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlower_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:34:50 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:31:11 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function recursively prints an unsigned long long number
in lowercase hexadecimal.*/

void	ft_hexlower_pf(unsigned long long n, int *count)
{
	char	*hexdigits;

	hexdigits = "0123456789abcdef";
	if (n >= 16)
		ft_hexlower_pf(n / 16, count);
	ft_putchar_pf(hexdigits[n % 16], count);
}
