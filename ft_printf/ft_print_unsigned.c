/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:29:15 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/26 16:59:48 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_howmanydigit(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	char		*str;
	int			i;

	i = ft_howmanydigit(n);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (!n)
		str[0] = '0';
	while (n)
	{	
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{	
	int		len;
	char	*str;

	str = ft_itoa_unsigned(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}
