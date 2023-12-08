/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:05:20 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 13:37:27 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_reverse_rotate(t_list **stack, t_ps *ps)
{
	t_list	*node;
	t_list	*current;
	t_list	*head;
	t_list	*end;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error("Insufficient Arguments for rotate");
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
	ps->steps++;
	return (*stack);
}

t_list	*ps_rra(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stackb);
	return (ps_reverse_rotate(stacka, ps));
}

t_list	*ps_rrb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stacka);
	return (ps_reverse_rotate(stackb, ps));
}

void	ps_rrr(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_reverse_rotate(stacka, ps);
	ps_reverse_rotate(stackb, ps);
}
