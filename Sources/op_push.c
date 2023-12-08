/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:58:18 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 13:34:21 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_push(t_list **stacki, t_list **stacko, t_ps *ps)
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
	ps->steps++;
	return (*stacki);
}

t_list	*ps_pa(t_list **stacka, t_list **stackb, t_ps *ps)
{
	return (ps_push(stacka, stackb, ps));
}

t_list	*ps_pb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	return (ps_push(stackb, stacka, ps));
}

void	ps_donothing(t_list **stack)
{
	t_list	*head;

	head = *stack;
}
