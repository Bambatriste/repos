/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:34:25 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 17:13:24 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fill_buffer(t_data *infos, char c)
{
	if (infos->size < 1024)
	{
		infos->buffer[infos->size] = c;
		infos->read++;
		infos->size++;
		infos->buffer[infos->size] = '\0';
	}
	if (infos->size == 1024)
	{
		flush_buffer(infos);
	}
}

void	flush_buffer(t_data *infos)
{
	write(1, infos->buffer, infos->size);
	infos->size = 0;
	infos->buffer[0] = '\0';
}
