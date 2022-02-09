/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 00:32:05 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/12 20:55:18 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_numerical(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int signe;
	int i;
	int returned_int;

	i = 0;
	returned_int = 0;
	signe = 1;
	while (is_space(str[i]) && str[i])
	{
		i++;
	}
	while ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
		{
			signe = -signe;
		}
		i++;
	}
	while (is_numerical(str[i]) && (str[i]))
	{
		returned_int = returned_int * 10 + (str[i] - '0');
		i++;
	}
	return (returned_int * signe);
}
