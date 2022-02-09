/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 07:14:05 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/21 21:31:31 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base(int nb, char *base, char *str, int len);
int		ft_get_sign(char *nbr);
int		ft_skip(char *nbr);
int		inbase(char c, char *base);

int		is_space(char c)
{
	if (c == '\f' || c == '\t' || c == '\n'
			|| c == '\r' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

int		ft_check_base(char *base)
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
			if (base[i] == base[j] && j != i)
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

long	ft_convert_str(char c, char *base)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (base[i])
	{
		if (c == base[i])
			nb = i;
		i++;
	}
	return (nb);
}

int		get_len_base(long nb, char *base)
{
	int	j;
	int i;

	j = 0;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		j++;
	}
	while (base[i])
		i++;
	while (nb / i > 0)
	{
		j++;
		nb = nb / i;
	}
	j++;
	return (j);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	long	nb;
	int		i;
	long	l;
	long	len;

	l = 0;
	nb = 0;
	str = NULL;
	if (!(ft_check_base(base_from)))
		return (NULL);
	if (!(ft_check_base(base_to)))
		return (NULL);
	while (base_from[l])
		l++;
	i = ft_skip(nbr) - 1;
	while (nbr[++i] && inbase(nbr[i], base_from))
		nb = (nb * l) + ft_convert_str(nbr[i], base_from);
	nb = nb * (ft_get_sign(nbr));
	l = 0;
	len = get_len_base(nb, base_to);
	if (!(str = malloc(sizeof((*str) * len))))
		return (NULL);
	ft_putnbr_base((int)nb, base_to, str, len);
	return (str);
}
