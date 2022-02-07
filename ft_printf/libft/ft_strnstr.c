/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:31:34 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 19:00:28 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	char		*haystack2;
	size_t		i;
	size_t		y;

	haystack2 = (char *)haystack;
	i = 0;
	if (!*needle)
		return (haystack2);
	while (len > i && haystack2[i])
	{
		y = 0;
		while (haystack2[i + y] == needle[y] && len > i + y)
		{
			if (needle[y + 1] == '\0')
				return (&haystack2[i]);
			y++;
		}
		i++;
	}
	return (NULL);
}
