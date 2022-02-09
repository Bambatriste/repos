/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:10:28 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/14 15:01:01 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int nb_total;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	nb_total = nb;
	while (nb > 1)
	{
		nb_total = nb_total * (nb - 1);
		nb--;
	}
	return (nb_total);
}
