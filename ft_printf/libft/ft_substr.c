/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:57:08 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 19:01:57 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > (size_t)ft_strlen(s))
		sub = (char *)ft_calloc((size_t)ft_strlen(s) + 1, sizeof(char));
	else
		sub = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
		sub[i++] = s[start++];
	return (sub);
}
