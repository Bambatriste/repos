/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 01:48:18 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/07 12:18:41 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int str_len;

	str_len = 0;
	while (str[str_len])
	{
		if (str[str_len] < '0' || str[str_len] > '9')
		{
			return (0);
		}
		str_len++;
	}
	return (1);
}
