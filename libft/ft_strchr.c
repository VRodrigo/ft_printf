/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:33:52 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/10 10:51:42 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	size_t	i;

	chr = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == chr)
		return ((char *)(s + i));
	return (0);
}
