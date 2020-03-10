/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:47:48 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/04 18:18:55 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_perc(t_data_args *list)
{
	list->width--;
	if (list->zero == 1 && list->minus == 0)
		display_fill(list, '0');
	else if (list->minus == 0)
		display_fill(list, ' ');
	ft_putchar_fd('%', 1);
	if (list->minus == 1)
		display_fill(list, ' ');
	list->len++;
}
