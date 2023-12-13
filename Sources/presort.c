/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:55:09 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/13 16:03:59 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	set_quadrants(t_ps *ps)
{
	int	*arr;
	int	quarter;
	int	i;
	int	j;

	i = 1;
	j = 0;
	arr = bubblesort(ps);
	quarter = ps->itemcount / 4;
	while (i < ps->itemcount)
	{
		if (i % quarter == 0 && j < 3)
		{
			ps->quadrets[j] = arr[i + 1];
			j++;
		}
		i++;
	}
	ps->quadrets[j] = arr[i - 1];
}

t_list	*push_quadrants(t_ps *ps, t_list **stacka, t_list **stackb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ps->itemcount < 4)
	{
		while (i++ < ps->itemcount)
			ps_pb(stacka, stackb, ps);
		return (*stacka);
	}
	set_quadrants(ps);
	while (j < countnodes(*stacka))
	{
		if (*((int *)((*stacka)->content)) <= ps->quadrets[i] \
		|| (*stacka)->next == NULL)
			ps_pb(stacka, stackb, ps);
		else if ((*stacka)->next != NULL && j++)
			ps_ra(stacka, stackb, ps);
		if (j == countnodes(*stacka) && i++ < 4)
			j = 0;
	}
	ft_printf("\nTotal Steps: %d\n", ps->steps);
	return (*stacka);
}
