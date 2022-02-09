/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:33:13 by aedouard          #+#    #+#             */
/*   Updated: 2020/03/02 17:03:38 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	check_pre(const char *fmt, t_data *infos)
{
	if (fmt[infos->i] == '.')
	{
		infos->pre = 1;
		infos->i++;
	}
}

void	check_star(const char *fmt, t_data *infos)
{
	if (fmt[infos->i] == '*')
	{
		if (!(infos->pre))
			infos->star1 = 1;
		else
			infos->star2 = 1;
		infos->i++;
	}
}

int		is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.')
		return (1);
	return (0);
}

void	check_flags(const char *fmt, t_data *infos)
{
	while (is_flag(fmt[infos->i]))
	{
		if (fmt[infos->i] == '-')
			infos->neg = 1;
		if (fmt[infos->i] == '0')
			infos->zero = 1;
		if (fmt[infos->i] == '*')
		{
			if (!(infos->pre))
				infos->star1 = 1;
			else
				infos->star2 = 1;
		}
		if (fmt[infos->i] == '.')
			infos->pre = 1;
		infos->i++;
	}
}

void	check_number(const char *fmt, t_data *infos)
{
	check_star(fmt, infos);
	while (ft_isdigit(fmt[infos->i]))
	{
		if (!infos->star1 && !infos->pre)
			infos->number1 = infos->number1 * 10 + fmt[infos->i] - '0';
		else if (!infos->star2 && infos->pre)
			infos->number2 = infos->number2 * 10 + fmt[infos->i] - '0';
		infos->i++;
	}
}
