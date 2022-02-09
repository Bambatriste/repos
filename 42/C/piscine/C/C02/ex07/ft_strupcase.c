/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:03:29 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/07 12:22:48 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int str_len;

	str_len = 0;
	while (str[str_len])
	{
		if (str[str_len] >= 'a' && str[str_len] <= 'z')
		{
			str[str_len] = str[str_len] - 32;
		}
		str_len++;
	}
	return (str);
}
