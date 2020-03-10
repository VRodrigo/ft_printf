/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:45:05 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/04 19:28:35 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data_args	*list;

	if (!(list = (t_data_args*)malloc(sizeof(t_data_args))))
		return (-1);
	list->format = format;
	list->i = 0;
	list->len = 0;
	reinicialice(list);
	va_start(list->args, format);
	list->len = data_display(list);
	va_end(list->args);
	free(list);
	return (list->len);
}
