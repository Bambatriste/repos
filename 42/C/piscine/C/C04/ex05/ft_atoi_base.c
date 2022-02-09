/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:38:15 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/22 22:22:51 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\r'
			|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base == NULL)
		return (0);
	while (base[i])
	{
		if (is_space(base[i]) || base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i] && (j != i))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (i == 1 || i == 0)
		return (0);
	return (1);
}

int		ft_convert_str(char c, char *base)
{
	int i;
	int nb;
	int j;

	i = 0;
	j = 0;
	nb = 0;
	while (base[j])
	{
		if (c == base[j])
		{
			nb = j;
		}
		j++;
	}
	j = 0;
	return (nb);
}

int		inbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int nb;
	int signe;
	int i;
	int l;

	nb = 0;
	i = 0;
	l = 0;
	signe = 1;
	if (!check_base(base))
		return (0);
	while (base[l])
		l++;
	while (is_space(str[i]) && str[i])
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	i = i - 1;
	while (str[++i] && inbase(str[i], base))
		nb = (nb * l) + ft_convert_str(str[i], base);
	return (nb * signe);
}
