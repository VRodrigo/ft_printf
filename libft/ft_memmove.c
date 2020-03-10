/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:45:06 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/21 19:04:29 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	char		*src;

	dest = ((char *)s1);
	src = ((char *)s2);
	if (s1 == s2)
		return (s1);
	if (s1 > s2)
	{
		while (n > 0)
		{
			n--;
			dest[n] = src[n];
		}
	}
	else if (s1 < s2)
		ft_memcpy(s1, s2, n);
	return (s1);
}
