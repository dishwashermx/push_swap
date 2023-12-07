/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:05:20 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/07 14:00:40 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	ps_reverse_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*current;
	t_list	*head;
	t_list	*end;

	if (*stack == NULL || (*stack)->next == NULL)
		return ((void)error("Insufficient Arguments for rotate"));
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
}

void	ps_rra(t_list **stacka, t_list **stackb)
{
	ps_reverse_rotate(stacka);
	ps_donothing(stackb);
}

void	ps_rrb(t_list **stacka, t_list **stackb)
{
	ps_reverse_rotate(stackb);
	ps_donothing(stacka);
}

void	ps_rrr(t_list **stacka, t_list **stackb)
{
	ps_reverse_rotate(stacka);
	ps_reverse_rotate(stackb);
}
