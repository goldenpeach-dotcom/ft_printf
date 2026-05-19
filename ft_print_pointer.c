/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaneko <mkaneko@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 22:25:30 by mkaneko           #+#    #+#             */
/*   Updated: 2026/05/19 10:18:30 by mkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long n)
{
	static char	base[] = "0123456789abcdef";
	int			count;

	count = 0;
	if (n >= 16)
		count += print_pointer(n / 16);
	write(1, &base[n % 16], 1);
	return (count + 1);
}

int	print_ptr(va_list *args)
{
	unsigned long		addr;
	void				*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
		return (print_str("(nil)"));
	addr = (unsigned long)ptr;
	print_str("0x");
	return (2 + print_pointer(addr));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
