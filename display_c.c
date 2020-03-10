/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:41:12 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/04 18:11:34 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_c(t_data_args *list)
{
	char c;

	c = (char)va_arg(list->args, int);
	list->width--;
	if (list->zero == 1 && list->minus == 0)
		display_fill(list, '0');
	else if (list->minus == 0)
		display_fill(list, ' ');
	ft_putchar_fd(c, 1);
	if (list->minus == 1)
		display_fill(list, ' ');
	list->len++;
}
