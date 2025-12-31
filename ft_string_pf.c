/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:04:36 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:32:22 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function prints a string to the standar output. It also update
the character count with the number of characteres */

void	ft_string_pf(char *args, int *count)
{
	if (!args)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (*args != '\0')
	{
		ft_putchar_pf(*args, count);
		args++;
	}
}
