/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupper_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:31:15 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:31:25 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* The ft_hexupper_pf function recursively prints an unsigned long long number
in uppercase hexadecimal format.*/

void	ft_hexupper_pf(unsigned long long n, int *count)
{
	char	*hexdigits;

	hexdigits = "0123456789ABCDEF";
	if (n >= 16)
		ft_hexupper_pf(n / 16, count);
	ft_putchar_pf(hexdigits[n % 16], count);
}
