/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:42:12 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:23:11 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_s(t_data_args *list)
{
	char	*s;
	char	*aux;
	int		len;

	aux = (char *)va_arg(list->args, char *);
	if (aux == NULL)
		aux = "(null)";
	len = ft_strlen(aux);
	if (len > list->prec_v && list->prec == 1)
		s = ft_substr(aux, 0, list->prec_v);
	else
		s = aux;
	list->len += ft_strlen(s);
	list->width -= ft_strlen(s);
	if (list->zero == 1 && list->minus == 0)
		display_fill(list, '0');
	else if (list->minus == 0)
		display_fill(list, ' ');
	ft_putstr_fd(s, 1);
	if (list->minus == 1)
		display_fill(list, ' ');
}
