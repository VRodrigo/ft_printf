/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:47:21 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/21 16:02:26 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_elem;
	t_list	*next_elem;

	next_elem = *lst;
	while (next_elem)
	{
		current_elem = next_elem;
		next_elem = current_elem->next;
		ft_lstdelone(current_elem, del);
	}
	*lst = NULL;
}
