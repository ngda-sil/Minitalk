/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:22:05 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 19:01:40 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s2;
	size_t		i;
	size_t		lasts1;
	size_t		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	lasts1 = ft_strlen(s1);
	while (ft_strchr(set, s1[lasts1]) != NULL && lasts1 != 0)
		lasts1--;
	while (ft_strchr(set, s1[i]) != NULL && i != ft_strlen(s1) - 1)
		i++;
	if (!lasts1)
		s2 = (char *)ft_calloc(1, sizeof(char));
	else
		s2 = (char *)ft_calloc(lasts1 - i + 2, sizeof(char));
	if (!s2)
		return (NULL);
	while (i <= lasts1)
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}
