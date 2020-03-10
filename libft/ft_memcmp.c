/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:45:51 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/20 12:35:33 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*str1;
	const char		*str2;
	size_t			i;
	unsigned char	chr1;
	unsigned char	chr2;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			chr1 = str1[i];
			chr2 = str2[i];
			return (chr1 - chr2);
		}
		i++;
	}
	return (0);
}
