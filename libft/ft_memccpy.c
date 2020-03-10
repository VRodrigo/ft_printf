/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:10:25 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/13 17:56:55 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;
	unsigned char			a;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == a)
			return (dst + i + 1);
		i++;
	}
	return ((void *)0);
}
