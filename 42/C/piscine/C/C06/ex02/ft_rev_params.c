/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:23:55 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/15 13:17:35 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int j;

	j = 0;
	while (ac >= 2)
	{
		while (av[ac - 1][j])
		{
			ft_putchar(av[ac - 1][j]);
			j++;
		}
		j = 0;
		ac--;
		ft_putchar(10);
	}
	return (0);
}
