/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lol_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:00:38 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/22 10:01:18 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;

	if (max > min)
	{
		size = max - min;
		if (!(*range = (int*)malloc(sizeof(**range) * size)))
			return (-1);
		i = min;
		while (i < max)
		{
			(*range)[i - min] = i;
			i++;
		}
		return (size);
	}
	else
	{
		*range = NULL;
		return (0);
	}
}
