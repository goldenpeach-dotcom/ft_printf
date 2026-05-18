/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:19:46 by mkaneko           #+#    #+#             */
/*   Updated: 2026/05/18 16:09:54 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char	*format, ...);
int		handle_format(char specifier, va_list *args);

int		print_char(char c);
int		print_str(const char	*str);
int		print_digit(unsigned long long n, int base, int upper);
int		print_unsigned(va_list	*args);
int		print_ptr(va_list *args);
int		print_int(va_list *args);
int		print_hex(va_list *args, int upper);
int		print_pointer(unsigned long n);
size_t	ft_strlen(const char *str);

#endif