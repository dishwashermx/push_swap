/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:58:18 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/13 11:31:54 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_push(t_list **stacki, t_list **stacko)
{
	t_list	*node;

	if (*stacki == NULL)
	{
		error("Insufficient Arguments for Push");
		return (*stacki);
	}
	node = *stacki;
	*stacki = (*stacki)->next;
	node->next = *stacko;
	*stacko = node;
	return (*stacki);
}

t_list	*ps_pb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_push(stacka, stackb);
	add_ops("pb");
	ps->steps++;
	return (*stacka);
}

t_list	*ps_pa(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_push(stackb, stacka);
	add_ops("pa");
	ps->steps++;
	return (*stacka);
}

void	ps_donothing(t_list **stack)
{
	t_list	*head;

	head = *stack;
}
