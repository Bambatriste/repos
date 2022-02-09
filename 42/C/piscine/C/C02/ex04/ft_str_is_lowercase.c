/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:20:35 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/07 12:20:57 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int str_len;

	str_len = 0;
	while (str[str_len])
	{
		if (str[str_len] < 'a' || str[str_len] > 'z')
		{
			return (0);
		}
		str_len++;
	}
	return (1);
}
