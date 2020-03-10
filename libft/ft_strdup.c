/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:28:08 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/13 17:24:03 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1);
	s = (char *)ft_calloc(len + 1, sizeof(char));
	if (!s)
		return ((void *)0);
	ft_strlcpy(s, s1, len + 1);
	return (s);
}
