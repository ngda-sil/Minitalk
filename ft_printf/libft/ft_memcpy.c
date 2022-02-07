/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:06:15 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 18:46:44 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*src2;
	char		*dst2;

	if (!dst && !src)
		return (0);
	src2 = (const char *)src;
	dst2 = (char *)dst;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	while (i < n)
		dst2[i++] = '\0';
	return ((void *)dst2);
}
