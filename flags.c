/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:49:25 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:49:00 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_number_width(t_data_args *list)
{
	while (list->format[list->i] >= '0' && list->format[list->i] <= '9')
	{
		if (list->arg_width == 1)
		{
			list->width = 0;
			list->arg_width = 0;
		}
		list->width *= 10;
		list->width += list->format[list->i] - '0';
		list->i++;
	}
}

void	flag_adj(t_data_args *list)
{
	int i;

	while (list->format[list->i] == '*')
	{
		i = va_arg(list->args, int);
		if (i < 0)
		{
			list->minus = 1;
			list->width = -i;
		}
		else if (i >= 0)
			list->width = i;
		list->arg_width = 1;
		list->i++;
	}
	get_number_width(list);
}

void	get_number_prec(t_data_args *list)
{
	while ((list->format[list->i] >= '0' && list->format[list->i] <= '9'))
	{
		if (list->arg_prec == 1)
		{
			list->prec_v = 0;
			list->arg_prec = 0;
		}
		list->prec_v *= 10;
		list->prec_v += list->format[list->i] - '0';
		list->i++;
	}
}

void	flag_prec(t_data_args *list)
{
	int i;

	while (list->format[list->i] == '.')
	{
		list->prec = 1;
		list->i++;
	}
	while (list->format[list->i] == '*' && list->prec == 1)
	{
		i = va_arg(list->args, int);
		if (i < 0)
		{
			i = 0;
			list->prec = 0;
		}
		list->prec_v = i;
		list->arg_prec = 1;
		list->i++;
	}
	get_number_prec(list);
}
