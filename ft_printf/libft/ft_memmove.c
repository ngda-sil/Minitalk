/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:27:55 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/05 14:47:38 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	if (!dst && !src)
		return (NULL);
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	while (0 < len)
	{
		len--;
		((char *)dst)[len] = ((char *)src)[len];
	}
	return (dst);
}
