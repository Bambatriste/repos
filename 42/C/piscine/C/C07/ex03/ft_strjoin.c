/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:16:27 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/22 15:24:36 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		check_size(char **ret_p, int size)
{
	if (size <= 0)
	{
		if (!(ret_p[0] = (char *)malloc(sizeof(char))))
			return (0);
		ret_p[0][0] = '\0';
		return (0);
	}
	return (1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*ret;
	int		str_size;
	int		tot_size;

	ret = NULL;
	if (!check_size(&ret, size))
		return (ret);
	i = -1;
	str_size = 0;
	while (++i < size)
		str_size = str_size + (ft_strlen(strs[i]));
	tot_size = str_size + (ft_strlen(sep) * size) - (ft_strlen(sep));
	if (!(ret = (char *)malloc(sizeof(char) * (tot_size + 1))))
		return (ret);
	ret[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(ret, strs[i]);
		i++;
		if (i < size)
			ft_strcat(ret, sep);
	}
	return (ret);
}
