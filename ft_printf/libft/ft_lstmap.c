/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:52:31 by ngda-sil          #+#    #+#             */
/*   Updated: 2021/11/18 19:03:13 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*save;

	newlst = NULL;
	while (lst)
	{
		if (!newlst)
		{
			newlst = ft_lstnew(f(lst->content));
			save = newlst;
			lst = lst->next;
			if (!newlst)
				return (NULL);
		}
		newlst->next = ft_lstnew(f(lst->content));
		if (newlst->next == NULL)
		{
			ft_lstclear(&save, del);
			return (NULL);
		}
		lst = lst->next;
		newlst = newlst->next;
	}
	return (save);
}
