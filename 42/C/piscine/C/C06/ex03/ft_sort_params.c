/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:23:55 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/15 13:15:13 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char **tab, int ac)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_putchar(10);
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i] || s2[i] > s1[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] && !s2[i]) || (s2[i] && !s1[i]))
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp;
	int		nb_swaps;

	i = 1;
	j = 0;
	nb_swaps = 1;
	while (nb_swaps != 0)
	{
		nb_swaps = 0;
		i = 0;
		while (i < ac - 1)
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				temp = av[i + 1];
				av[i + 1] = av[i];
				av[i] = temp;
				nb_swaps++;
			}
			i++;
		}
	}
	ft_print(av, ac);
}
