/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:10:10 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/02 17:40:27 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_buffer_size_u(t_data *infos, int size)
{
	if (infos->number1 > size && infos->number1 > infos->number2)
		infos->buffer_size = infos->number1;
	else if (infos->number2 > size)
		infos->buffer_size = infos->number2;
	else if (infos->buffer_size <= size)
		infos->buffer_size = size;
}

void	fill_buff_right_u(t_data *infos, int size, int nb)
{
	int		i;

	i = 0;
	while (i < infos->pre_s)
	{
		fill_buffer(infos, '0');
		i++;
	}
	if (size)
		fill_nbr(nb, infos, size);
	i = 0;
	while (i < infos->fill_s)
	{
		fill_buffer(infos, ' ');
		i++;
	}
}

void	fill_buff_left_u(t_data *infos, int size, int nb)
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
		fill_nbr(nb, infos, size);
}

void	convert_u(va_list ap, t_data *infos)
{
	unsigned int	nbr;
	int				size;

	nbr = va_arg(ap, unsigned int);
	size = getlen(nbr);
	if (infos->pre && nbr == 0 && !infos->number2)
		size = 0;
	get_buffer_size_u(infos, size);
	infos->pre_s = infos->number2 - size;
	if (infos->pre_s < 0)
		infos->pre_s = 0;
	infos->fill_s = infos->buffer_size - infos->pre_s - size;
	if (infos->neg)
		fill_buff_right_u(infos, size, nbr);
	else
		fill_buff_left_u(infos, size, nbr);
}
