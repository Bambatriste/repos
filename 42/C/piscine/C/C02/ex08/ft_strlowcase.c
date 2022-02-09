/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:01:58 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/07 12:23:34 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int str_len;

	str_len = 0;
	while (str[str_len])
	{
		if (str[str_len] >= 'A' && str[str_len] <= 'Z')
		{
			str[str_len] = str[str_len] + 32;
		}
		str_len++;
	}
	return (str);
}
