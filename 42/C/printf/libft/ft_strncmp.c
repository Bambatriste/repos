/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:54:19 by aedouard          #+#    #+#             */
/*   Updated: 2019/11/18 14:40:53 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	s1cpy = (unsigned char*)s1;
	s2cpy = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1cpy[i] != s2cpy[i] || (!s1cpy[i] || !(s2cpy[i])))
			return (s1cpy[i] - s2cpy[i]);
		i++;
	}
	return (0);
}
