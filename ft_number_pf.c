/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:38:50 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:31:37 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* The ft_number_pf function prints an integer n and updates the count with
the number of characters printed, handling negative numbers and the minimum
32-bit integer. It uses recursion to print each digit.*/

void	ft_number_pf(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_pf('-', count);
		n = -n;
	}
	if (n > 9)
	{
		ft_number_pf(n / 10, count);
	}
	ft_putchar_pf((n % 10) + '0', count);
}
