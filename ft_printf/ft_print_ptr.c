/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:57:09 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/24 22:30:53 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_howmanydigit(unsigned long long n)
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

static int	ft_print_addr(unsigned long long n)
{
	int	i;

	i = ft_howmanydigit(n);
	if (n < 16)
	{
		if (n <= 9)
			ft_printchar(n + '0');
		else
			ft_printchar(n + 87);
	}
	else
	{
		ft_print_addr(n / 16);
		ft_print_addr(n % 16);
	}
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	int					i;
	unsigned long long	n;

	n = (unsigned long long)ptr;
	i = write(1, "0x", 2);
	i += ft_print_addr(n);
	return (i);
}
