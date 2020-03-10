/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:40:16 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:22:38 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		display_fill_i(t_data_args *list, char c, int num)
{
	int i;

	i = 0;
	if ((list->width) > 0)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			num = -num;
			list->len++;
		}
		while (i < (list->width))
		{
			write(1, &c, 1);
			i++;
		}
		list->len += list->width;
	}
	return (num);
}

void	display_fill(t_data_args *list, char c)
{
	int i;

	i = 0;
	if ((list->width) > 0)
	{
		while (i < (list->width))
		{
			write(1, &c, 1);
			i++;
		}
		list->len += list->width;
	}
}

int		display_prec_fill(t_data_args *list, char c, int num)
{
	int i;

	i = 0;
	if ((list->prec_v) > 0)
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			num = -num;
			list->len++;
		}
		while (i < (list->prec_v))
		{
			write(1, &c, 1);
			i++;
		}
		list->len += list->prec_v;
	}
	return (num);
}
