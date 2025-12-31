/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:14:06 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:32:16 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Writes a character to the standard output and updates the count*/

void	ft_putchar_pf(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}
