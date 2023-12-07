/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:25:14 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/01 15:07:09 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	ps_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ((void)error("Insufficient Arguments for swap"));
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ps_sa(t_list **stacka, t_list **stackb)
{
	ps_swap(stacka);
	ps_donothing(stackb);
}

void	ps_sb(t_list **stacka, t_list **stackb)
{
	ps_donothing(stacka);
	ps_swap(stackb);
}

void	ps_ss(t_list **stacka, t_list **stackb)
{
	ps_swap(stacka);
	ps_swap(stackb);
}
