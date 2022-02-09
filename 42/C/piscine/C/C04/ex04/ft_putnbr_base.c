/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:37:02 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/22 22:08:17 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid(char c)
{
	if (c == '+' || c == '-')
		return (0);
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (0);
	return (1);
}

int		checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base == NULL)
		return (0);
	while (base[i])
	{
		if (!is_valid(base[i]))
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		i;
	char	c;
	long	nb;

	if (!checkbase(base))
		return ;
	i = 0;
	nb = (long)nbr;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	while (base[i])
		i++;
	base_len = i;
	if (nb > base_len - 1)
		ft_putnbr_base(nb / base_len, base);
	c = base[nb % base_len];
	write(1, &c, 1);
}
