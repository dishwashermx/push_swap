/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:54:16 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/22 16:53:22 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	countpos(t_list **stacka, t_list **stackb, t_list *lowest, int code)
{
	t_list	*stacka2;
	t_list	*stackb2;
	t_list	*big;
	int		pos;

	pos = 0;
	stacka2 = *stacka;
	stackb2 = *stackb;
	big = largestmodule(stacka2);
	while (*(int *)lowest->content != *(int *)stacka2->content && pos < 500)
	{
		stacka2 = stacka2->next;
		pos++;
	}
	if (code == 1)
		pos++;
	// printf("pos is %d\n", pos);
	return (pos);
}

int	findpos(t_list **stacka, t_list **stackb, int code)
{
	t_list	*stacka2;
	t_list	*stackb2;
	t_list	*lowest;
	t_list	*compare;

	stacka2 = *stacka;
	stackb2 = *stackb;
	lowest = largestmodule(stacka2);
	if (code == 1)
		return (countpos(stacka, stackb, lowest, 1));
	while (stacka2 != NULL)
	{
		if (*(int *)stackb2->content < *(int *)stacka2->content)
		{
			compare = stacka2;
			if (*(int *)compare->content < *(int *)lowest->content)
				lowest = compare;
		}
		stacka2 = stacka2->next;
	}
	if (*(int *)lowest->content < *(int *)stackb2->content)
		return (countpos(stacka, stackb, lowest, 1));
	return (countpos(stacka, stackb, lowest, 0));
}

void	pushintopos(t_list **stacka, t_list **stackb, t_ps *ps, int pos)
{
	int	i;

	if (pos == countnodes(*stacka))
	{
		return ((void)ps_pa(stacka, stackb, ps));
	}
	else if (pos <= (countnodes(*stacka) + 1) / 2)
	{
		i = 0;
		while (i < pos)
		{
			ps_ra(stacka, stackb, ps);
			i++;
		}
	}
	else
	{
		i = countnodes(*stacka);
		while (i > pos)
		{
			ps_rra(stacka, stackb, ps);
			i--;
		}
	}
	ps_pa(stacka, stackb, ps);
}

void	pushback(t_list **stacka, t_list **stackb, t_ps *ps, int pos)
{
	int	i;

	if (pos == countnodes(*stacka))
	{
		ps_pa(stacka, stackb, ps);
	}
	else if (pos <= (countnodes(*stacka) + 1) / 2)
	{
		i = 0;
		while (i < pos)
		{
			ps_ra(stacka, stackb, ps);
			i++;
		}
	}
	else
	{
		i = countnodes(*stacka);
		while (i > pos)
		{
			ps_rra(stacka, stackb, ps);
			i--;
		}
	}
}

void	bigsort(t_list **stacka, t_list **stackb, t_ps *ps)
{
	int		chunks;
	int		pos;

	if (countnodes(*stacka) == 100)
		chunks = 4;
	else
		chunks = 12;
	push_chunks(stacka, stackb, ps, chunks);
	smallsort(ps, stacka, stackb);
	while ((*stackb) != NULL)
	{
		// printlists(*stacka, *stackb);
		pos = findpos(stacka, stackb, 0);
		pushintopos(stacka, stackb, ps, pos);
	}
	pos = findpos(stacka, stackb, 1);
	pushback(stacka, stackb, ps, pos);
}
