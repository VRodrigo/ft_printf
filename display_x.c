/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:46:45 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:35:08 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_gaps(t_data_args *list)
{
	if (list->minus == 0 && list->zero == 0)
		display_fill(list, ' ');
	else if (list->zero == 1 && list->minus == 0 && list->prec == 0)
		display_fill(list, '0');
	else if (list->prec == 1 && list->minus == 0)
		display_fill(list, ' ');
	if (list->prec == 1 || list->prec_v > 0)
		display_prec_fill(list, '0', 1);
}

void	display_x(t_data_args *list)
{
	unsigned int	num;
	char			*str;

	num = (unsigned int)va_arg(list->args, unsigned int);
	if (list->format[list->i] == 'x')
		str = ft_int_to_hex_u(num, 'a');
	else
		str = ft_int_to_hex_u(num, 'A');
	if (list->prec == 1 && list->prec_v == 0 && num == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	list->prec_v -= ft_strlen(str);
	if (list->prec_v < 0)
		list->width -= ft_strlen(str);
	else
		list->width -= (ft_strlen(str) + list->prec_v);
	display_gaps(list);
	ft_putstr_fd(str, 1);
	if (list->minus == 1)
		display_fill(list, ' ');
	list->len += ft_strlen(str);
	free(str);
}
