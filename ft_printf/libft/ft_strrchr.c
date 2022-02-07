/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:41:52 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 19:00:51 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (*s)
		s++;
	while (*s != (char)c && i >= 0)
	{
		s--;
		i--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
