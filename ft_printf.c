/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:57 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:31:52 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* This function identifies the format specifier and calls the corresponding
function to handle the printing of that specific type, updating the
character count as necessary. */

// %c print a single character
// %s print a string of characters
// %p the void* pointer argument is printed in hexadecimal
// %d print a decimal number (base 10)
// %i print an integer in base 10
// %u print an unsigned decimal number (base 10)
// %x print a number in hexadecimal (base 16) with lowercase
// %X print a number in hexadecimal (base 16) with uppercase
// %% print a percent sign

static void	ft_format(char s, va_list args, int *count)
{
	if (s == 'c')
		ft_putchar_pf(va_arg(args, int), count);
	else if (s == 's')
		ft_string_pf(va_arg(args, char *), count);
	else if (s == 'p')
		ft_pointer_pf(va_arg(args, unsigned long long), count);
	else if (s == 'd' || s == 'i')
		ft_number_pf(va_arg(args, int), count);
	else if (s == 'u')
		ft_unint_pf(va_arg(args, unsigned int), count);
	else if (s == 'x')
		ft_hexlower_pf(va_arg(args, unsigned int), count);
	else if (s == 'X')
		ft_hexupper_pf(va_arg(args, unsigned int), count);
	else if (s == '%')
		ft_putchar_pf('%', count);
	else
		ft_putchar_pf(s, count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (0);
	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				ft_format(format[i], args, &count);
		}
		else
		{
			ft_putchar_pf(format[i], &count);
		}
		i++;
	}
	va_end(args);
	return (count);
}

/* 
#include <stdio.h>

int	main(void)
{
	int				n;
	char			*str;
	int				num;
	char			c;
	unsigned int	hex_num;

	hex_num = 255;
	str = "hola";
	c = 'a';
	num = -42;
	n = ft_printf("hola mundo");
	ft_printf("\n");
	printf("Devuelve: %d\n", ft_printf("n: %d", n));
	printf("Deberia ser: %d\n", printf("n: %d", n));
	ft_printf("\n");
	ft_printf("c: %c", c);
	ft_printf("\n");
	ft_printf("s: %s", str);
	ft_printf("\n");
	ft_printf("p: %p", str);
	ft_printf("\n");
	str = NULL;
	ft_printf("p: %p", str);
	ft_printf("\n");
	ft_printf("Hexadecimal (minúscula): %x", hex_num);
	ft_printf("\n");
	ft_printf("Hexadecimal (mayúscula): %X", hex_num);
	return (0);
}
*/
