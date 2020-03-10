/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_prec_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:35:32 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/10 11:32:17 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adj_width_i(t_data_args *list, int i)
{
	size_t	size;
	int		nb;

	nb = i;
	size = 0;
	if (i <= 0)
	{
		size++;
		i = -i;
	}
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	if (list->prec == 1 && list->prec_v == 0 && nb == 0)
		return ;
	list->width -= size;
	if (list->prec_v >= 0)
		list->width -= list->prec_v;
}

void	adj_prec_i(t_data_args *list, int i)
{
	size_t size;
	int nb;

	nb = i;
	size = 0;
	if (i == 0)
		size++;
	if (i < 0)
		i = -i;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	if (list->prec_v == 0 && nb == 0)
		list->prec_zero = 1;
	else
		list->prec_v -= size;
}

void	adj_width_u(t_data_args *list, unsigned int i)
{
	size_t size;

	size = 0;
	if (i == 0)
		size++;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	list->width -= size;
}
