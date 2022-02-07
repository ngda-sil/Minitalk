/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:42:54 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/24 22:34:10 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(va_list args, const char input, int i)
{
	if (input == 'c')
		i += ft_printchar(va_arg(args, int));
	else if (input == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (input == 'p')
		i += ft_print_ptr(va_arg(args, void *));
	else if (input == 'd' || input == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (input == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (input == 'x' || input == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), input);
	else if (input == '%')
		i += ft_printchar('%');
	return (i);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		char_printed;
	va_list	args;

	i = 0;
	char_printed = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] != '%')
			char_printed += ft_printchar(input[i]);
		else
		{
			i++;
			char_printed = ft_conversion(args, input[i], char_printed);
		}
		i++;
	}
	va_end(args);
	return (char_printed);
}
