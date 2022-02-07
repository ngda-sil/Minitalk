/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:39:44 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 18:36:33 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_howmanydigit(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	i = ft_howmanydigit(n);
	nb = n;
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (!nb)
		str[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = (char) '-';
	}
	while (nb)
	{	
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
