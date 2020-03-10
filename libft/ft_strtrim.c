/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:54:33 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/20 11:07:26 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	len_s;

	if (!s1 || !set)
		return ((void *)0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_s = ft_strlen(s1);
	if (len_s != 0)
		while (len_s && ft_strchr(set, s1[len_s]))
			len_s--;
	str = ft_substr((char *)s1, 0, len_s + 1);
	return (str);
}
