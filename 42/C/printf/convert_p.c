/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:59:01 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 22:29:33 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_buffer_size_p(t_data *infos, int size)
{
	if (infos->number1 > size && infos->number1 > infos->number2)
		infos->buffer_size = infos->number1;
	else if (infos->number2 > size)
		infos->buffer_size = infos->number2;
	else if (infos->buffer_size <= size)
		infos->buffer_size = size;
}

void	fill_buff_right_p(t_data *infos, int size, unsigned long int n)
{
	int		i;

	i = 0;
	while (i < infos->pre_s)
	{
		fill_buffer(infos, '0');
		i++;
	}
	fill_buffer(infos, '0');
	fill_buffer(infos, 'x');
	fill_x(n, size - 2, infos);
	i = 0;
	while (i < infos->fill_s)
	{
		fill_buffer(infos, ' ');
		i++;
	}
}

void	fill_buff_left_p(t_data *infos, int size, unsigned long int n)
{
	int		i;

	i = 0;
	while (i < infos->fill_s)
	{
		fill_buffer(infos, infos->filler);
		i++;
	}
	i = 0;
	while (i < infos->pre_s)
	{
		fill_buffer(infos, '0');
		i++;
	}
	fill_buffer(infos, '0');
	fill_buffer(infos, 'x');
	fill_x(n, size - 2, infos);
}

void	convert_p(va_list ap, t_data *infos)
{
	unsigned long int	n;
	int					size;

	n = va_arg(ap, unsigned long int);
	size = get_len_x(n);
	if (infos->pre && n == 0 && !infos->number2)
		size = 0;
	size = size + 2;
	get_buffer_size_p(infos, size);
	infos->pre_s = infos->number2 - size;
	if (infos->pre_s < 0)
		infos->pre_s = 0;
	infos->fill_s = infos->buffer_size - infos->pre_s - size;
	if (infos->neg)
		fill_buff_right_p(infos, size, n);
	else
		fill_buff_left_p(infos, size, n);
}
