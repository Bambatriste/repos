/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:23:12 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/15 08:44:05 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int temp_nb;

	temp_nb = nb;
	if (power == 0 && nb == 0)
		return (1);
	else if (power < 0 || nb == 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		temp_nb = temp_nb * nb;
		power--;
	}
	return (temp_nb);
}
