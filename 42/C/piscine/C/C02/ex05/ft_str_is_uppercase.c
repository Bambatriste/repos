/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:35:20 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/06 10:41:17 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int str_len;

	str_len = 0;
	while (str[str_len])
	{
		if (str[str_len] > 'Z' || str[str_len] < 'A')
		{
			return (0);
		}
		str_len++;
	}
	return (1);
}
