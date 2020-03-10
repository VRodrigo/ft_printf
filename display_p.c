/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:43:13 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/06 13:15:43 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_int_to_hex_u(size_t value, char a)
{
	size_t	value_c;
	int		size;
	char	*str;
	char	*base_tab;

	size = 1;
	if (a == 'a')
		base_tab = "0123456789abcdef";
	else if (a == 'A')
		base_tab = "0123456789ABCDEF";
	value_c = value;
	while (value_c /= 16)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = base_tab[value % 16];
		size--;
		value /= 16;
	}
	return (str);
}

void	display_hex_low(char *str, t_data_args *list)
{
	list->width -= (ft_strlen(str) + 2);
	if (list->zero == 1 && list->minus == 0)
		display_fill(list, '0');
	else if (list->minus == 0)
		display_fill(list, ' ');
	ft_putstr_fd("0x", 1);
	list->len += 2;
	if (list->prec == 1)
		display_prec_fill(list, '0', 1);
	ft_putstr_fd(str, 1);
	if (list->minus == 1)
		display_fill(list, ' ');
	free(str);
}

void	display_p(t_data_args *list)
{
	void		*ptr;
	size_t		num;
	char		*str;

	ptr = (void *)va_arg(list->args, void *);
	num = (size_t)&(*ptr);
	str = ft_int_to_hex_u(num, 'a');
	if (list->prec == 1 && list->prec_v == 0 && num == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (list->prec == 1)
	{
		list->prec_v -= ft_strlen(str);
		list->zero = 0;
	}
	list->len += ft_strlen(str);
	display_hex_low(str, list);
}
