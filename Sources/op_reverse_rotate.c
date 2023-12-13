/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:05:20 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/13 11:32:17 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_reverse_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*current;
	t_list	*head;
	t_list	*end;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error("Insufficient Arguments for Reverse Rotate");
		return (*stack);
	}
	current = *stack;
	head = *stack;
	end = *stack;
	while ((current)-> next != NULL)
	{
		current = (current)->next;
		if (current->next != NULL)
			end = end->next;
	}
	node = current;
	node->next = head;
	end->next = NULL;
	*stack = node;
	return (*stack);
}

t_list	*ps_rra(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stackb);
	ps_reverse_rotate(stacka);
	add_ops("rra");
	ps->steps++;
	return (*stacka);
}

t_list	*ps_rrb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stacka);
	ps_reverse_rotate(stackb);
	add_ops("rrb");
	ps->steps++;
	return (*stacka);
}

void	ps_rrr(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_reverse_rotate(stacka);
	ps_reverse_rotate(stackb);
	add_ops("rrr");
	ps->steps++;
}
