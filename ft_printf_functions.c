/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:04:36 by mkaneko           #+#    #+#             */
/*   Updated: 2026/05/20 19:44:20 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(const char	*str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	print_digit(unsigned long long n, int base, int upper)
{
	int				count;
	static char		base_lower[] = "0123456789abcdef";
	static char		base_upper[] = "0123456789ABCDEF";
	char			*b;
	int				res;

	if (upper)
		b = base_upper;
	else
		b = base_lower;
	count = 0;
	if (n >= (unsigned long long)base)
		count = count + print_digit(n / base, base, upper);
	res = write (1, &b[n % base], 1);
	if (res < 0)
		return (-1);
	return (count + 1);
}

int	print_unsigned(va_list	*args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (print_digit((unsigned long long)n, 10, 0));
}
