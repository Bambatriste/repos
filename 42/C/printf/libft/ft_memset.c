/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:25:27 by aedouard          #+#    #+#             */
/*   Updated: 2019/11/18 12:27:26 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *bcpy;

	bcpy = (unsigned char*)b;
	while (len)
	{
		*bcpy = (unsigned char)c;
		bcpy++;
		len--;
	}
	return (b);
}
