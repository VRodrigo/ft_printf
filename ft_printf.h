/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrodrigo <vrodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:39:23 by vrodrigo          #+#    #+#             */
/*   Updated: 2020/03/09 12:06:16 by vrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_data_args
{
	const char	*format;
	va_list		args;
	size_t		i;
	int			len;
	int			minus;
	int			zero;
	int			width;
	int			arg_width;
	int			prec;
	int			prec_v;
	int			prec_zero;
	int			arg_prec;
}				t_data_args;

void			adj_width_i(t_data_args *list, int i);
void			adj_prec_i(t_data_args *list, int i);
void			adj_width_u(t_data_args *list, unsigned int i);
int				args_display(t_data_args *list);
void			reinicialice(t_data_args *list);
int				data_display(t_data_args *list);
void			display_c(t_data_args *list);
void			display_fill(t_data_args *list, char c);
int				display_fill_i(t_data_args *list, char c, int num);
int				display_prec_fill(t_data_args *list, char c, int num);
void			display_i(t_data_args *list);
char			*ft_int_to_hex_u(size_t value, char a);
void			display_hex_low(char *str, t_data_args *list);
void			display_p(t_data_args *list);
void			display_perc(t_data_args *list);
void			display_s(t_data_args *list);
void			ft_putunbr_fd(unsigned int nbr, int fd);
void			display_u(t_data_args *list);
void			display_x(t_data_args *list);
void			flag_minus(t_data_args *list);
void			flag_zero(t_data_args *list);
void			flag_adj(t_data_args *list);
void			flag_prec(t_data_args *list);
int				ft_printf(const char *format, ...);
void			display_gaps(t_data_args *list);

#endif
