/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:29:44 by aedouard          #+#    #+#             */
/*   Updated: 2019/11/19 14:30:54 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *scpy;
	unsigned char		ccpy;

	scpy = (unsigned char*)s;
	ccpy = (unsigned char)c;
	while (n)
	{
		if (*scpy == ccpy)
			return ((void*)scpy);
		scpy++;
		n--;
	}
	return (NULL);
}
