/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:36:16 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/23 13:27:39 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	threesort(t_list **stacka, t_list **stackb, t_ps *ps)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

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
	int		pos;

	threesort(stacka, stackb, ps);
	while ((*stackb) != NULL)
	{
		pos = findpos(stacka, stackb, 0);
		pushintopos(stacka, stackb, ps, pos);
	}
	pos = findpos(stacka, stackb, 1);
	pushback(stacka, stackb, ps, pos);
}

void	smallsort(t_ps *ps, t_list **stacka, t_list **stackb)
{
	if (countnodes(*stacka) == 3)
		threesort(stacka, stackb, ps);
	else if (countnodes(*stacka) > 3)
	{
		while (countnodes(*stacka) > 3)
			ps_pb(stacka, stackb, ps);
		fivesort(stacka, stackb, ps);
	}
	return ;
}
