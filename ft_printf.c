/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:04:36 by mkaneko           #+#    #+#             */
/*   Updated: 2026/05/18 13:25:48 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	va_start(args, format);
	if (!format)
		return (-1);
	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			total_len = total_len + handle_format(format[i + 1], &args);
			i = i + 2;
		}
		else
		{
			write (1, &format[i], 1);
			total_len++;
			i++;
		}
	}
	va_end(args);
	return (total_len);
}

int	handle_format(char specifier, va_list *args)
{
	if (specifier == 'd' || specifier == 'i')
		return (print_int(args));
	if (specifier == 'c')
		return (print_char(va_arg(*args, int)));
	if (specifier == 's')
		return (print_str(va_arg(*args, const char *)));
	if (specifier == 'p')
		return (print_ptr(args));
	if (specifier == 'u')
		return (print_unsigned(args));
	if (specifier == 'x')
		return (print_hex(args, 0));
	if (specifier == 'X')
		return (print_hex(args, 1));
	if (specifier == '%')
		return (write(1, "%", 1));
	return (0);
}

int	print_int(va_list *args)
{
	int		n;
	long	nn;
	int		count;

	n = va_arg(*args, int);
	nn = n;
	count = 0;
	if (nn < 0)
	{
		write(1, "-", 1);
		nn = -nn;
		count++;
	}
	count = count + print_digit((unsigned long long)nn, 10, 0);
	return (count);
}

int	print_hex(va_list *args, int upper)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (print_digit((unsigned long long)n, 16, upper));
}
