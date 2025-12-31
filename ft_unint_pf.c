/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:09:50 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:32:28 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function recursively prints an unsigned integer in base 10, converting
each digit to a character and keeping track of the printed characters.*/

void	ft_unint_pf(unsigned int n, int*count)
{
	if (n > 9)
	{
		ft_unint_pf(n / 10, count);
		ft_unint_pf(n % 10, count);
	}
	else
	{
		ft_putchar_pf(n + '0', count);
	}
}
