/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:37:32 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/21 18:35:47 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (haystack == needle)
		return ((char*)haystack);
	if (needle[0] == '\0')
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	pos = 0;
	while (haystack[pos] != '\0' && (size_t)pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char*)&haystack[pos]);
		}
		++pos;
	}
	return (0);
}
