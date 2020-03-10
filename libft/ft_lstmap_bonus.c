/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:25:10 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/21 19:16:58 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*begg;

	if (!lst || !(n_list = ft_lstnew(f(lst->content))))
		return (NULL);
	begg = n_list;
	while (lst)
	{
		if (lst->next)
		{
			if (!(n_list->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&begg, del);
				return (NULL);
			}
			n_list = n_list->next;
		}
		lst = lst->next;
	}
	n_list->next = NULL;
	return (begg);
}
