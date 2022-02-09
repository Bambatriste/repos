/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:37:53 by aedouard          #+#    #+#             */
/*   Updated: 2021/10/06 18:38:03 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_stack **la, t_stack **lb)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*acpy;

	if (*lb == NULL)
		return ;
	acpy = (t_stack *)(*la);
	*la = *lb;
	a = (t_stack *)*la;
	b = (t_stack *)*lb;
	b = b->next;
	*lb = b;
	a->next = acpy;
}

void	s(t_stack **la)
{
	t_stack	*a1;
	t_stack	*a2;

	if (*la == NULL)
		return ;
	a2 = (t_stack *)*la;
	a1 = (t_stack *)*la;
	if (a1->next == NULL)
		return ;
	a1 = a1->next;
	a2->next = a1->next;
	a1->next = a2;
	*la = a1;
}

void	ss(t_stack **la, t_stack **lb)
{
	s(la);
	s(lb);
}
