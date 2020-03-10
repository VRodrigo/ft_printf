/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:44:28 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:22:15 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_size(int i)
{
	size_t size;

	size = 0;
	if (i < 0)
	{
		i = -i;
		size = 1;
	}
	while (i /= 10)
		size++;
	return (size);
}

void	display_i(t_data_args *list)
{
	int i;

	i = (int)va_arg(list->args, int);
	if (list->prec == 1)
	{
		adj_prec_i(list, i);
		list->zero = 0;
	}
	if (list->width > 0)
		adj_width_i(list, i);
	if (list->minus == 0 && list->zero == 0)
		display_fill_i(list, ' ', 1);
	else if (list->zero == 1 && list->minus == 0)
		i = display_fill_i(list, '0', i);
	if (list->prec == 1)
		i = display_prec_fill(list, '0', i);
	(list->prec == 1 && list->prec_zero == 1) ? 0 : ft_putnbr_fd(i, 1);
	(list->prec == 1 && list->prec_zero == 1) ? 0 : (list->len +=
		nbr_size(i) + 1);
	if (list->minus == 1)
		display_fill(list, ' ');
}
