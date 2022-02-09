/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:57:29 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/02 15:34:44 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	get_buffer_size_s(t_data *infos)
{
	infos->n2cpy = infos->number2;
	if (infos->number2 < infos->str_size && infos->pre)
		infos->str_size = infos->number2;
	if (infos->number1 > infos->str_size)
		infos->buffer_size = infos->number1;
	else if (infos->buffer_size <= infos->str_size)
		infos->buffer_size = infos->str_size;
}

void	fill_buff_right_s(t_data *infos, char *s)
{
	int i;

	i = 0;
	while (i < infos->str_size)
	{
		fill_buffer(infos, s[i]);
		i++;
	}
	while (i < infos->buffer_size)
	{
		fill_buffer(infos, ' ');
		i++;
	}
}

void	fill_buff_left_s(t_data *infos, char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < infos->buffer_size - infos->str_size)
	{
		fill_buffer(infos, infos->filler);
		i++;
	}
	while (i < infos->buffer_size)
	{
		fill_buffer(infos, s[j]);
		i++;
		j++;
	}
}

void	convert_s(va_list ap, t_data *infos)
{
	char *s;

	s = va_arg(ap, char*);
	if (!s)
		s = "(null)";
	infos->str_size = ft_strlen(s);
	get_buffer_size_s(infos);
	if (infos->neg)
		fill_buff_right_s(infos, s);
	else
		fill_buff_left_s(infos, s);
}
