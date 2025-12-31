/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:34:40 by adruz-to          #+#    #+#             */
/*   Updated: 2025/07/13 18:32:06 by adruz-to         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// standar libraries

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);

// format functions

void	ft_putchar_pf(char c, int *count);
void	ft_string_pf(char *args, int *count);
void	ft_pointer_pf(unsigned long long pointer, int *count);
void	ft_number_pf(int n, int *count);
void	ft_unint_pf(unsigned int n, int *count);
void	ft_hexlower_pf(unsigned long long n, int *count);
void	ft_hexupper_pf(unsigned long long n, int *count);

#endif
