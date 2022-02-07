/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:31:53 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/24 22:29:57 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_howmanydigit(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 16)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_print_hex(unsigned int n, const char c)
{
	int	i;

	i = ft_howmanydigit(n);
	if (n < 16)
	{
		if (n <= 9)
			ft_printchar(n + '0');
		else
		{
			if (c == 'x')
				ft_printchar(n + 87);
			else if (c == 'X')
				ft_printchar(n + 55);
		}
	}
	else
	{
		ft_print_hex((n / 16), c);
		ft_print_hex((n % 16), c);
	}
	return (i);
}
