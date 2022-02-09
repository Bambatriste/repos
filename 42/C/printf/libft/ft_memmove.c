/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:54:36 by aedouard          #+#    #+#             */
/*   Updated: 2019/11/18 12:54:08 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstcpy;
	char	*srccpy;

	dstcpy = (char*)dst;
	srccpy = (char*)src;
	if (dstcpy > srccpy)
	{
		while (len)
		{
			dstcpy[len - 1] = srccpy[len - 1];
			len--;
		}
	}
	else
		dstcpy = ft_memcpy(dst, src, len);
	return (dstcpy);
}
