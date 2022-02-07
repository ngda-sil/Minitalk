/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:29:05 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/12 18:33:51 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tabptr;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if (!s)
		return (NULL);
	tabptr = (char **)ft_calloc(ft_nbwords(s, c) + 1, sizeof(char *));
	if (tabptr == NULL)
		return (NULL);
	while (s[i] && l < ft_nbwords(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		tabptr[l++] = ft_substr(s, (unsigned int)i, (size_t)j);
		i += j;
	}
	return (tabptr);
}
