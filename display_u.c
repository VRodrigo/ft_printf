/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:45:38 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:29:16 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int nbr, int fd)
{
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
	}
	ft_putchar_fd(nbr % 10 + '0', fd);
}

int		unbr_size(unsigned int i)
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

void	display_u(t_data_args *list)
{
	unsigned int i;

	i = (unsigned int)va_arg(list->args, unsigned int);
	if (list->prec == 1)
	{
		adj_prec_i(list, i);
		list->zero = 0;
	}
	if (list->width > 0)
		adj_width_i(list, i);
	if (list->minus == 0 && list->zero == 0)
		display_fill(list, ' ');
	else if (list->zero == 1 && list->minus == 0)
		display_fill(list, '0');
	if (list->prec == 1)
		display_prec_fill(list, '0', 1);
	(i == 0 && list->prec == 1 && list->prec_v == 0) ? 0 : ft_putunbr_fd(i, 1);
	(list->prec == 1 && list->prec_zero == 1) ? 0 : (list->len +=
		unbr_size(i) + 1);
	if (list->minus == 1)
		display_fill(list, ' ');
}
