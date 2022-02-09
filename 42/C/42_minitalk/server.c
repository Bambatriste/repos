/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:08:38 by aedouard          #+#    #+#             */
/*   Updated: 2021/11/01 14:16:00 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_str(char **str, char *buff, int *i)
{
	*str = ft_strjoin(*str, buff);
	ft_putstr_fd(*str, 1);
	ft_bzero(buff, 4096);
	*i = 0;
	free(*str);
	*str = NULL;
}

void	handler(int signal)
{
	static int	i = 0;
	static int	count = 8;
	static char	buff[4096] = {'\0'};
	static char	*str = NULL;

	count--;
	if (!str)
		str = ft_strdup("");
	if (signal == SIGUSR2)
		buff[i] |= (1 << count);
	if (count == 0)
	{
		if (buff[i] == '\0')
			print_str(&str, buff, &i);
		else if (i == 4095)
		{
			str = ft_strjoin(str, buff);
			ft_bzero(buff, 4096);
			i = 0;
		}
		else
			i++;
		count = 8;
	}
}

int	main(int ac, char **av)
{
	pid_t	id;

	if (ac != 1)
		return (1);
	(void)av;
	id = getpid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
