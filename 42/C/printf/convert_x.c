/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:19:11 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 22:36:02 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_buffer_size_x(t_data *infos, int size)
{
	if (infos->number1 > size && infos->number1 > infos->number2)
		infos->buffer_size = infos->number1;
	else if (infos->number2 > size)
		infos->buffer_size = infos->number2;
	else if (infos->buffer_size <= size)
		infos->buffer_size = size;
}

void	fill_buff_right_x(t_data *infos, int size, unsigned int n)
{
	int		i;

	i = 0;
	while (i < infos->pre_s)
	{
		fill_buffer(infos, '0');
		i++;
	}
	i = 0;
	if (size)
		fill_x(n, size, infos);
	while (i < infos->fill_s)
	{
		fill_buffer(infos, ' ');
		i++;
	}
}

void	fill_buff_left_x(t_data *infos, int size, unsigned int n)
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
	if (size)
		fill_x(n, size, infos);
}

void	convert_x(va_list ap, t_data *infos, char spec)
{
	unsigned int	nb;
	int				size;

	nb = va_arg(ap, unsigned int);
	size = get_len_x(nb);
	if (infos->pre && nb == 0 && !infos->number2)
		size = 0;
	if (spec == 'X')
		infos->up = 1;
	get_buffer_size_x(infos, size);
	infos->pre_s = infos->number2 - size;
	if (infos->pre_s < 0)
		infos->pre_s = 0;
	infos->fill_s = infos->buffer_size - infos->pre_s - size;
	if (infos->neg)
		fill_buff_right_x(infos, size, nb);
	else
		fill_buff_left_x(infos, size, nb);
}
