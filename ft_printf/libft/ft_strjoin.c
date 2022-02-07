/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:58:26 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 18:58:52 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	k = ft_strlen(s2);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (j < i)
	{
		s[j++] = *s1++;
	}
	while (j < i + k)
	{
		s[j++] = *s2++;
	}
	s[j] = '\0';
	return (s);
}
