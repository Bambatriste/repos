/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 06:53:30 by aedouard          #+#    #+#             */
/*   Updated: 2019/08/21 18:27:30 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		get_next_sep(int i, char *str, char *charset)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	while (str[i])
	{
		if (is_sep((str[i]), charset))
			return (i);
		i++;
	}
	return (size);
}

int		count_words(char *str, char *charset, int i)
{
	int word;
	int len;
	int size;

	word = 0;
	size = 0;
	len = 0;
	while (str[size])
		size++;
	while (str[i])
	{
		if (is_sep(str[i], charset) && len > 0)
		{
			word++;
			len = 0;
		}
		else if (!is_sep(str[i], charset))
		{
			len++;
			if ((i + 1) == size)
				word++;
		}
		i++;
	}
	return (word);
}

char	*strcopy(int start, int end, char *str, char *split)
{
	int len;
	int i;

	i = 0;
	len = end - start;
	if (!(split = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (start < end)
	{
		split[i] = str[start];
		start++;
		i++;
	}
	split[i] = '\0';
	return (split);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		start;
	int		end;
	int		i;
	int		nb_word;

	i = -1;
	start = 0;
	split = NULL;
	while (is_sep(str[start], charset))
		start++;
	end = get_next_sep(start, str, charset);
	nb_word = count_words(str, charset, i + 1);
	if (!(split = malloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	split[nb_word] = 0;
	while (++i < nb_word)
	{
		split[i] = strcopy(start, end, str, split[i]);
		start = end;
		while (is_sep(str[start], charset))
			start++;
		end = get_next_sep(start, str, charset);
	}
	return (split);
}
