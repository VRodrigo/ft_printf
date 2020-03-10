/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:50:01 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 11:51:17 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_to_abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int		ft_neg(int value, int base)
{
	if (value < 0 && base == 10)
		return (1);
	return (0);
}

char	*ft_itoa_base(int value, int base, char *base_tab)
{
	int			size;
	int			value_c;
	int			sign;
	char		*str;

	size = 1;
	if (base < 2 || base > 16)
		return (0);
	sign = ft_neg(value, base);
	value_c = value;
	while (value_c /= base)
		size++;
	str = (char *)malloc(sizeof(char) * (size + sign + 1));
	str[size] = '\0';
	while (size > sign)
	{
		str[size - 1] = base_tab[ft_to_abs(value % base)];
		size--;
		value /= base;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
