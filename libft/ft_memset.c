/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:05:40 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/09 16:32:25 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	size_t			i;
	char			*s;

	s = b;
	a = c;
	i = 0;
	while (i < len)
	{
		s[i] = a;
		i++;
	}
	return (b);
}
