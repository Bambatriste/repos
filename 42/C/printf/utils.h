/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:47:17 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 22:25:37 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_data
{
	int				zero;
	char			filler;
	int				neg;
	int				pre;
	int				star1;
	int				star2;
	int				number1;
	int				number2;
	int				nb_neg;
	int				size;
	int				buffer_size;
	int				n2cpy;
	int				i;
	int				read;
	int				fill_s;
	int				pre_s;
	int				str_s;
	int				add;
	int				str_size;
	int				up;
	char			buffer[1024];
}					t_data;
int					ft_printf(const char *fmt, ...);
int					is_flag(char c);
void				check_pre (const char *fmt, t_data *infos);
void				check_star (const char *fmt, t_data *infos);
void				check_flags(const char *fmt, t_data *infos);
void				check_number(const char *fmt, t_data *infos);
void				convert(int type, va_list ap, t_data *infos);
void				convert_s(va_list ap, t_data *infos);
void				convert_d(va_list ap, t_data *infos);
void				convert_c(va_list ap, t_data *infos, char c);
void				convert_u(va_list ap, t_data *infos);
void				convert_x(va_list ap, t_data *infos, char spec);
void				convert_p(va_list ap, t_data *infos);
int					getlen(unsigned int n);
void				convert_stars(va_list ap, t_data *infos);
void				fill_buffer(t_data *infos, char c);
void				flush_buffer(t_data *infos);
void				fill_nbr(unsigned int n, t_data *infos, int len);
void				fill_x(unsigned long int n, int size, t_data *infos);
char				*create_str_x(unsigned long int n
					, int size, char *x, t_data *infos);
int					get_len_x(unsigned long int n);
#endif
