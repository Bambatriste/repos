/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:56:32 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/08 12:28:08 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_max_size(int size1, int size2)
{
	if (size1 > size2)
		return (size1);
	else
		return (size2);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	int				j;
	int				size_max;
	unsigned char	test1;
	unsigned char	test2;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	size_max = get_max_size(i, j);
	i = 0;
	while (i < size_max)
	{
		test1 = (unsigned char)s1[i];
		test2 = (unsigned char)s2[i];
		if (test1 > test2 || test2 > test1)
			return (test1 - test2);
		i++;
	}
	return (0);
}
