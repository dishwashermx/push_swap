/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:16 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/19 17:37:25 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	threesort(t_list **stacka, t_list **stackb, t_ps *ps)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (checksorted(stacka) == 1)
		return ;
	first = *stacka;
	second = (*stacka)->next;
	third = second->next;
	if (*(int *)(first->content) < *(int *)(second->content))
	{
		if (*(int *)(first->content) < *(int *)(third->content))
			return ((void)(ps_sa(stacka, stackb, ps) \
			, (void)(ps_ra(stacka, stackb, ps))));
		else
			return ((void)(ps_rra(stacka, stackb, ps)));
	}
	if (*(int *)(first->content) < *(int *)(third->content))
		return ((void)(ps_sa(stacka, stackb, ps)));
	else if (*(int *)(second->content) < *(int *)(third->content))
		return ((void)(ps_ra(stacka, stackb, ps)));
	else
		return ((void)(ps_sa(stacka, stackb, ps) \
		, (void)(ps_rra(stacka, stackb, ps))));
}

void	fivesort(t_list **stacka, t_list **stackb, t_ps *ps)
{
	int		i;
	t_list	*stacka2;

	i = 0;
	threesort(stacka, stackb, ps);
	stacka2 = *stacka;
	while (*stackb != NULL)
	{
		if (*((int *)((*stackb)->content)) < *(int *)(stacka2->content))
		{
			fivepushintopos(stacka, stackb, ps, i);
			i = 0;
			stacka2 = *stacka;
		}
		else if (stacka2->next == NULL)
		{
			ps_pa(stacka, stackb, ps);
			ps_ra(stacka, stackb, ps);
			i = 0;
			stacka2 = *stacka;
		}
		else if ((stacka2)->next != NULL)
		{
			stacka2 = stacka2->next;
			i++;
		}
	}
}

int	checksorted(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = (*stack)->next;
	while (second != NULL)
	{
		if (*(int *)(first->content) < *(int *)(second->content))
		{
			first = second;
			if (second->next == NULL)
				return(1);
			else
				second = second->next;
		}
		else
			return (0);
	}
	return (1);
}

void	smallsort(t_ps *ps, t_list **stacka, t_list **stackb)
{
	if (checksorted(stacka) == 1)
		return ;
	if (countnodes(*stacka) == 3)
		threesort(stacka, stackb, ps);
	else if (countnodes(*stacka) == 5)
	{
		while (countnodes(*stacka) > 3)
			ps_pb(stacka, stackb, ps);
		fivesort(stacka, stackb, ps);
	}
	return ;
}
