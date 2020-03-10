/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:52:17 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/06 15:10:22 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		args_display(t_data_args *list)
{
	if (list->format[list->i] == 'c')
		display_c(list);
	else if (list->format[list->i] == 's')
		display_s(list);
	else if (list->format[list->i] == 'p')
		display_p(list);
	else if (list->format[list->i] == 'd' || list->format[list->i] == 'i')
		display_i(list);
	else if (list->format[list->i] == 'u')
		display_u(list);
	else if (list->format[list->i] == 'x' || list->format[list->i] == 'X')
		display_x(list);
	else if (list->format[list->i] == '%')
		display_perc(list);
	else
		return (1);
	return (0);
}

void	reinicialice(t_data_args *list)
{
	list->minus = 0;
	list->width = 0;
	list->zero = 0;
	list->prec = 0;
	list->arg_width = 0;
	list->arg_prec = 0;
	list->prec_v = 0;
	list->prec_zero = 0;
}

int		data_display(t_data_args *list)
{
	int i;

	while (list->format[list->i] != '\0')
	{
		if (list->format[list->i] == '%')
		{
			list->i++;
			flag_zero(list);
			flag_minus(list);
			flag_adj(list);
			flag_prec(list);
			i = args_display(list);
			if (i == 1)
				break ;
			reinicialice(list);
		}
		else
		{
			ft_putchar_fd(list->format[list->i], 1);
			list->len++;
		}
		list->i++;
	}
	return (list->len);
}
