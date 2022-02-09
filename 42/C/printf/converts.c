/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:53:26 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/04 21:58:24 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	convert(int type, va_list ap, t_data *infos)
{
	if (type == 'c')
		convert_c(ap, infos, 'c');
	if (type == '%')
		convert_c(ap, infos, '%');
	if (type == 'd' || type == 'i')
		convert_d(ap, infos);
	if (type == 'u')
		convert_u(ap, infos);
	if (type == 's')
		convert_s(ap, infos);
	if (type == 'x')
		convert_x(ap, infos, 'x');
	if (type == 'X')
		convert_x(ap, infos, 'X');
	if (type == 'p')
		convert_p(ap, infos);
}
