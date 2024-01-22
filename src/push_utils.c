/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:13:40 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/19 17:36:26 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	rotatefront(t_list **stacka, t_list **stackb, t_ps *ps, int pos)
{
	if (countnodes(*stacka) == 4 && pos == 2)
		return ((void)ps_ra(stacka, stackb, ps), (void)ps_ra(stacka, stackb, ps), 3);
	if (pos == 1)
		return ((void)ps_ra(stacka, stackb, ps), 1);
	if ((countnodes(*stacka) == 4 && pos == 3) || pos == 2)
		return ((void)ps_rra(stacka, stackb, ps), 4);
	return (0);
}

void	rotateback(t_list **stacka, t_list **stackb, t_ps *ps, int i)
{
	if (i == 3)
		return ((void)ps_rra(stacka, stackb, ps), (void)ps_rra(stacka, stackb, ps));
	if (i == 1)
		return ((void)ps_rra(stacka, stackb, ps));
	if (i == 4)
		return ((void)ps_ra(stacka, stackb, ps), (void)ps_ra(stacka, stackb, ps));
}

void	fivepushintopos(t_list **stacka, t_list **stackb, t_ps *ps, int pos)
{
	int	i;

	i = rotatefront(stacka, stackb, ps, pos);
	ps_pa(stacka, stackb, ps);
	if (i != 0)
		rotateback(stacka, stackb, ps, i);
	return ;
}

void	ps_donothing(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (head == NULL)
		return ;
	if (head->next != NULL)
		head = head->next;
	return ;
}
