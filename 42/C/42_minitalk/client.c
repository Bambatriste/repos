/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:51:10 by aedouard          #+#    #+#             */
/*   Updated: 2021/11/01 14:15:39 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	count;
	int	bit_value;

	count = 8;
	bit_value = -1;
	while (count --)
	{
		bit_value = ((1 << count) & c) != 0;
		if (bit_value == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (bit_value == 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	str = av[2];
	send_str(pid, str);
	return (0);
}
