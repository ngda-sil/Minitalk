/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:19:40 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/24 21:58:13 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{	
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}
