/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 00:42:38 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/07 12:16:45 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int len_str;

	len_str = 0;
	while (str[len_str])
	{
		if ((str[len_str] > 'z') || (str[len_str] < 'A')
			|| ((str[len_str] > 'Z')
				&& (str[len_str] < 'a')))
		{
			return (0);
		}
		len_str++;
	}
	return (1);
}
