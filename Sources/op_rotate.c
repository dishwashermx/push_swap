/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:05:20 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/07 13:51:28 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	ps_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*current;
	t_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ((void)error("Insufficient Arguments for rotate"));
	head = *stack;
	node = *stack;
	current = *stack;
	head = (*stack)->next;
	while ((current)-> next != NULL)
		current = (current)->next;
	(current)->next = node;
	node->next = NULL;
	*stack = node;
}

void	ps_ra(t_list **stacka, t_list **stackb)
{
	ps_rotate(stacka);
	ps_donothing(stackb);
}

void	ps_rb(t_list **stacka, t_list **stackb)
{
	ps_rotate(stackb);
	ps_donothing(stacka);
}

void	ps_rr(t_list **stacka, t_list **stackb)
{
	ps_rotate(stacka);
	ps_rotate(stackb);
}
