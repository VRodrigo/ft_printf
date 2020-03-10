/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_mz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:44:52 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:45:05 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_minus(t_data_args *list)
{
	while (list->format[list->i] == '-')
	{
		list->minus = 1;
		list->i++;
	}
}

void	flag_zero(t_data_args *list)
{
	while (list->format[list->i] == '0')
	{
		if (list->minus == 0)
			list->zero = 1;
		list->i++;
	}
}
