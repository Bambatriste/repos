/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:10:50 by aedouard          #+#    #+#             */
/*   Updated: 2019/11/18 17:06:05 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == '\f'
	|| c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int sign;
	int i;
	int returned_int;

	i = 0;
	returned_int = 0;
	sign = 1;
	while (is_space(str[i]) && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]) && (str[i]))
	{
		returned_int = returned_int * 10 + str[i] - '0';
		i++;
	}
	return (returned_int * sign);
}
