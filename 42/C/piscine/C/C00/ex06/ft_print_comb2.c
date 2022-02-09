/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yolo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 10:47:42 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/04 10:15:16 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int a, int b)
{
	char a1;
	char a2;
	char b1;
	char b2;

	a1 = a / 10 + '0';
	a2 = a % 10 + '0';
	b1 = b / 10 + '0';
	b2 = b % 10 + '0';
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, &" ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
	if (a != 98)
	{
		write(1, &", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 99)
	{
		while (b < 99)
		{
			b++;
			if (a < b)
			{
				print(a, b);
			}
		}
		b = 0;
		a++;
	}
}
