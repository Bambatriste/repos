/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:56:59 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/07 12:33:02 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	is_alpha(int v)
{
	if (v > 'z' || v < 'A' || (v < 'a' && v > 'Z'))
	{
		return (0);
	}
	return (1);
}

char	is_numerical(int v)
{
	if (v < '0' || v > '9')
	{
		return (0);
	}
	return (1);
}

char	is_uppercase(int v)
{
	if (v > 'Z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int str_len;
	int last_char_is_alpha;
	int i;

	last_char_is_alpha = 0;
	str_len = 0;
	i = 0;
	while (str[i])
	{
		if (is_alpha(str[i]) && is_uppercase(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	while (str[str_len])
	{
		if (is_alpha(str[str_len]) && !is_uppercase(str[str_len])
				&& last_char_is_alpha == 0)
			str[str_len] = str[str_len] - 32;
		if (is_alpha(str[str_len]) || is_numerical(str[str_len]))
			last_char_is_alpha = 1;
		else
			last_char_is_alpha = 0;
		str_len++;
	}
	return (str);
}
