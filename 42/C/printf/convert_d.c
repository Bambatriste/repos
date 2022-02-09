/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_convert_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:20:30 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 16:57:13 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void				get_buffer_size(t_data *infos, int size)
{
	if (infos->number1 > size && infos->number1 > infos->number2)
		infos->buffer_size = infos->number1;
	else if (infos->number2 > size)
	{
		infos->buffer_size = infos->number2;
		if (infos->nb_neg)
			infos->buffer_size++;
	}
	else if (infos->buffer_size <= size)
	{
		infos->buffer_size = size;
		if (infos->nb_neg)
			infos->buffer_size++;
	}
}

void				fill_buff_right(t_data *infos, int size, unsigned int nb)
{
	int		i;

	i = 0;
	if (infos->nb_neg)
	{
		fill_buffer(infos, '-');
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
	i = 0;
	while (i < infos->fill_s)
	{
		fill_buffer(infos, ' ');
		i++;
	}
}

void				fill_buff_left(t_data *infos, int size, unsigned int nb)
{
	int		i;

	i = 0;
	if (infos->nb_neg && infos->zero)
		fill_buffer(infos, '-');
	while (i < infos->fill_s)
	{
		fill_buffer(infos, infos->filler);
		i++;
	}
	if (infos->nb_neg && !infos->zero)
		fill_buffer(infos, '-');
	i = 0;
	while (i < infos->pre_s)
	{
		fill_buffer(infos, '0');
		i++;
	}
	if (size)
		fill_nbr(nb, infos, size);
}

unsigned int		get_sign(int nbr, t_data *infos)
{
	unsigned int n;

	if (nbr < 0)
	{
		infos->nb_neg = 1;
		nbr++;
		nbr = -nbr;
		n = (unsigned int)nbr;
		n++;
	}
	else
		n = (unsigned int)nbr;
	return (n);
}

void				convert_d(va_list ap, t_data *infos)
{
	int				nbr;
	unsigned int	n;
	int				size;

	nbr = va_arg(ap, int);
	n = get_sign(nbr, infos);
	size = getlen(n);
	if (infos->pre && n == 0 && !infos->number2)
		size = 0;
	get_buffer_size(infos, size);
	infos->pre_s = infos->number2 - size;
	if (infos->pre_s < 0)
		infos->pre_s = 0;
	infos->fill_s = infos->buffer_size - infos->pre_s - size - infos->nb_neg;
	if (infos->neg)
		fill_buff_right(infos, size, n);
	else
		fill_buff_left(infos, size, n);
}
