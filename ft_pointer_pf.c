/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:58:05 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:31:47 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints a pointer address in hexadecimal format.*/

void	ft_pointer_pf(unsigned long long pointer, int *count)
{
	if (!pointer)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	write(1, "0x", 2);
	*count += 2;
	ft_hexlower_pf(pointer, count);
}
