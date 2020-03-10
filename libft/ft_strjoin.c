/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:31:25 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/01/20 13:47:18 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	o;

	if (!s1 || !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	o = 0;
	while (s1[i] != '\0')
		str[o++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
	{
		str[o] = s2[i];
		o++;
		i++;
	}
	str[o] = '\0';
	return (str);
}
