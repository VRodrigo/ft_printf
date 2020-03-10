/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:25:24 by cacorbal          #+#    #+#             */
/*   Updated: 2020/01/20 12:50:46 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_size;
	size_t src_size;
	size_t i;
	size_t j;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	if (dstsize < dst_size)
		return (src_size + dstsize);
	j = 0;
	i = dst_size;
	while (i < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (src_size + dst_size);
}
