/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnelson <lnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:26:40 by aedouard          #+#    #+#             */
/*   Updated: 2022/01/10 15:52:48 by lnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void *content)
{
	t_env_str	*content2;

	content2 = (t_env_str *)content;
	if (content2->env_display == 1)
	{
		if ((content2->value != NULL) && content2->value[0] != '\0')
			printf("%s=%s\n", content2->name, content2->value);
		else
			printf("%s\n", content2->name);
	}
}

void	builtin_env(t_list *lst_env)
{
	ft_lstiter(lst_env, print_env);
	g_exit_status = 0;
}
