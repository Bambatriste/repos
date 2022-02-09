/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:40:39 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/08 00:34:46 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	is_printable(char c)
{
	if (c < ' ' || c > '~')
	{
		return (0);
	}
	return (1);
}

void	hexa_print(unsigned char c)
{
	int			i;
	const char	hex[] = "0123456789abcdef";

	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int					i;
	unsigned char		j;

	i = 0;
	while (str[i])
	{
		if (is_printable(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			j = (unsigned char)str[i];
			hexa_print(j);
		}
		i++;
	}
}
