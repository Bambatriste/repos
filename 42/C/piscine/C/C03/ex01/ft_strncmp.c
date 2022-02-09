/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:33:15 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/08 23:00:01 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_max_size(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (i > j)
		return (i);
	else
		return (j);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	size_max;
	unsigned int	i;
	unsigned char	test1;
	unsigned char	test2;

	size_max = get_max_size(s1, s2);
	i = 0;
	while (i < size_max && i < n)
	{
		test1 = (unsigned char)s1[i];
		test2 = (unsigned char)s2[i];
		if (test1 > test2 || test2 > test1)
			return (test1 - test2);
		i++;
	}
	return (0);
}
