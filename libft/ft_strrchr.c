/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:18:55 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/10 12:48:43 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	size_t	len;

	chr = (char)c;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (len > 0)
	{
		if (s[len] == chr)
			return ((char *)(s + len));
		len--;
	}
	if (len == 0)
	{
		if (s[len] == chr)
			return ((char *)(s + len));
	}
	return (0);
}
