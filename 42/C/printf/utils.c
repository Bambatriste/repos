/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:40:03 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 22:37:42 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			getlen(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void		fill_nbr(unsigned int n, t_data *infos, int len)
{
	int lencpy;

	lencpy = len;
	if (len + infos->size > 1023)
		flush_buffer(infos);
	if (n == 0)
		infos->buffer[infos->size] = '0';
	infos->buffer[infos->size + len] = '\0';
	while (n)
	{
		infos->buffer[infos->size + len - 1] = (n % 10 + '0');
		len--;
		n = n / 10;
	}
	infos->read = infos->read + lencpy;
	infos->size = infos->size + lencpy;
}

void		convert_stars(va_list ap, t_data *infos)
{
	if (infos->star1)
		infos->number1 = va_arg(ap, int);
	if (infos->star2)
		infos->number2 = va_arg(ap, int);
}

int			get_len_x(unsigned long int n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void		fill_x(unsigned long int n, int size, t_data *infos)
{
	int			sizecpy;
	const char	base_hex[] = "0123456789abcdef";
	const char	base_hex_up[] = "0123456789ABCDEF";

	sizecpy = size;
	if (size + infos->size > 1023)
		flush_buffer(infos);
	infos->buffer[infos->size + size] = '\0';
	if (n == 0)
		infos->buffer[infos->size] = '0';
	while (n)
	{
		if (infos->up)
			infos->buffer[infos->size + size - 1] = base_hex_up[n % 16];
		else
			infos->buffer[infos->size + size - 1] = base_hex[n % 16];
		size--;
		n = n / 16;
	}
	infos->read = infos->read + sizecpy;
	infos->size = infos->size + sizecpy;
}
