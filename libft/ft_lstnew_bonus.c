/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:23:57 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/21 10:32:17 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_l;

	if (!(new_l = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
		new_l->content = NULL;
	else
	{
		new_l->content = content;
	}
	new_l->next = NULL;
	return (new_l);
}
