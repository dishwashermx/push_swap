/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:25:14 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 13:33:20 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

t_list	*ps_swap(t_list **stack, t_ps *ps)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return (*stack);
		error("Insufficient Arguments for swap");
	}
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ps->steps++;
	return (*stack);
}

t_list	*ps_sa(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stackb);
	return (ps_swap(stacka, ps));
}

t_list	*ps_sb(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_donothing(stacka);
	return (ps_swap(stackb, ps));
}

void	ps_ss(t_list **stacka, t_list **stackb, t_ps *ps)
{
	ps_swap(stacka, ps);
	ps_swap(stackb, ps);
}
