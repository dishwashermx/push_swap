/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:05:20 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 13:35:39 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_rotate(t_list **stack, t_ps *ps)
{
	t_list	*node;
	t_list	*current;
	t_list	*head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error("Insufficient Arguments for rotate");
		return (*stack);
	}
	node = *stack;
	current = *stack;
	head = (*stack)->next;
	while ((current)-> next != NULL)
		current = (current)->next;
	(current)->next = node;
	node->next = NULL;
	*stack = head;
	ps->steps++;
	return (*stack);
}

t_list	*ps_ra(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stackb);
	return (ps_rotate(stacka, ps));
}

t_list	*ps_rb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stacka);
	return (ps_rotate(stackb, ps));
}

void	ps_rr(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_rotate(stacka, ps);
	ps_rotate(stackb, ps);
}
