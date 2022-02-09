/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:08:42 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 22:26:23 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void				s_init(t_data *infos)
{
	infos->zero = 0;
	infos->neg = 0;
	infos->star1 = 0;
	infos->star2 = 0;
	infos->pre = 0;
	infos->number1 = 0;
	infos->number2 = 0;
	infos->n2cpy = 0;
	infos->filler = ' ';
	infos->nb_neg = 0;
	infos->str_size = 0;
	infos->buffer_size = 0;
	infos->pre_s = 0;
	infos->fill_s = 0;
	infos->str_s = 0;
	infos->add = 0;
	infos->up = 0;
}

void					adjust_flags(t_data *infos, va_list ap, char spec)
{
	convert_stars(ap, infos);
	if (infos->number2 < 0)
	{
		infos->pre = 0;
		infos->number2 = 0;
	}
	if (infos->pre && spec != 'c' && spec != '%')
		infos->zero = 0;
	if (infos->number1 < 0)
	{
		infos->neg = 1;
		infos->number1 = -infos->number1;
	}
	if (infos->zero && !infos->pre)
		infos->filler = '0';
}

int						is_spec(char c)
{
	if (c == 'd' || c == 'u' || c == 'c' || c == '%' || c == 's' || c == 'x'
	|| c == 'X' || c == 'i' || c == 'p')
		return (1);
	return (0);
}

static void				get_infos(const char *fmt, va_list ap, t_data *infos)
{
	while (fmt[infos->i])
	{
		if (fmt[infos->i] == '%')
		{
			infos->i++;
			check_flags(fmt, infos);
			check_number(fmt, infos);
			check_pre(fmt, infos);
			check_number(fmt, infos);
			adjust_flags(infos, ap, fmt[infos->i]);
			if (is_spec(fmt[infos->i]))
				convert(fmt[infos->i], ap, infos);
			if (!fmt[infos->i])
				return ;
			s_init(infos);
		}
		else
			fill_buffer(infos, fmt[infos->i]);
		infos->i++;
	}
}

int						ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_data	infos;

	s_init(&infos);
	infos.i = 0;
	infos.read = 0;
	infos.size = 0;
	infos.buffer[0] = '\0';
	va_start(ap, fmt);
	get_infos(fmt, ap, &infos);
	write(1, infos.buffer, infos.size);
	va_end(ap);
	return (infos.read);
}
