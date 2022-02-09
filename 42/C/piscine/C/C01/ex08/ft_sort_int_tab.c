/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:31:50 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/04 22:10:44 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int nb_swap;
	int temp;
	int i;
	int j;

	nb_swap = 1;
	while (nb_swap != 0)
	{
		nb_swap = 0;
		i = 0;
		j = 1;
		while (i < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
				nb_swap++;
			}
			i++;
			j++;
		}
	}
}
