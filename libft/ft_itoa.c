/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:48:02 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/21 19:14:22 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long int	integerlen(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void		putsign(char *str, int sign)
{
	if (sign < 0)
		str[0] = '-';
}

char		*ft_itoa(int n)
{
	long int		int_len;
	char			*str;
	unsigned int	nbr;
	int				sign;

	sign = 1;
	nbr = 0;
	int_len = integerlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (int_len + 1))))
		return (NULL);
	str[int_len--] = '\0';
	if (n < 0)
	{
		nbr = n * -1;
		sign = -1;
	}
	else
		nbr = n;
	while (int_len >= 0)
	{
		str[int_len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	putsign(str, sign);
	return (str);
}
