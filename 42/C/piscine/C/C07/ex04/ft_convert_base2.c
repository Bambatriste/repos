/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 07:36:27 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/21 21:32:16 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_base(char *base);
int		is_space(char c);

int		ft_get_sign(char *nbr)
{
	int i;
	int signe;

	i = 0;
	signe = 1;
	while (is_space(nbr[i]) && nbr[i])
		i++;
	while ((nbr[i] == '-' || nbr[i] == '+') && nbr[i])
	{
		if (nbr[i] == '-')
			signe = -signe;
		i++;
	}
	return (signe);
}

int		ft_skip(char *nbr)
{
	int i;

	i = 0;
	while (is_space(nbr[i]) && nbr[i])
		i++;
	while ((nbr[i] == '-' || nbr[i] == '+') && nbr[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nb, char *base, char *str, long len)
{
	int		base_len;
	int		neg;
	long	n;

	neg = 0;
	base_len = 0;
	n = (long)nb;
	if (!ft_check_base(base))
		return ;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str[len] = '\0';
	while (base[base_len])
		base_len++;
	while (len > 0)
	{
		len--;
		str[len] = base[n % base_len];
		n = n / base_len;
	}
	if (neg)
		str[len] = '-';
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
