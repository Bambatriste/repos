/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:46:01 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/08 20:24:24 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int size_to_find;

	i = 0;
	j = 0;
	size_to_find = 0;
	if (to_find[0] == '\0')
		return (str);
	while (to_find[size_to_find])
		size_to_find++;
	i = 0;
	while (str[j])
	{
		if (str[j] == to_find[i])
			i++;
		else if (str[j] == to_find[0])
			i = 1;
		else
			i = 0;
		if (i == size_to_find)
			return (&str[j + 1 - size_to_find]);
		j++;
	}
	return (0);
}
