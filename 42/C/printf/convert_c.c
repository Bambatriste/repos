/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:27:34 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/02 12:58:32 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_buffer_size_c(t_data *infos, int size)
{
	if (infos->number1 > size)
		infos->buffer_size = infos->number1;
	else if (infos->buffer_size <= size)
		infos->buffer_size = size;
}

void	fill_buff_right_c(t_data *infos, char c)
{
	int i;

	i = 0;
	fill_buffer(infos, c);
	i++;
	while (i < infos->buffer_size)
	{
		fill_buffer(infos, ' ');
		i++;
	}
}

void	fill_buff_left_c(t_data *infos, char c)
{
	int i;

	i = 0;
	while (i < infos->buffer_size - 1)
	{
		fill_buffer(infos, infos->filler);
		i++;
	}
	fill_buffer(infos, c);
}

void	convert_c(va_list ap, t_data *infos, char spec)
{
	char c;

	if (spec != '%')
		c = va_arg(ap, unsigned int);
	else
		c = '%';
	if (infos->zero)
		infos->filler = '0';
	get_buffer_size_c(infos, 1);
	if (infos->neg)
		fill_buff_right_c(infos, c);
	else
		fill_buff_left_c(infos, c);
}
