/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:55:09 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 16:21:06 by ghwa             ###   ########.fr       */
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
	printf("quarter = %d\n", quarter);
	while (i < ps->itemcount)
	{
		if (i % quarter == 0 && j < 3)
		{
			ps->quadrets[j] = arr[i + 1];
			printf("quadret %d: %d\n", j + 1, ps->quadrets[j]);
			j++;
		}
		i++;
	}
	ps->quadrets[j] = arr[i - 1];
	printf("quadret %d: %d\n", j, ps->quadrets[j]);
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
			ps_pa(stacka, stackb, ps);
		return (*stacka);
	}
	set_quadrants(ps);
	while (j < countnodes(*stacka))
	{
		if (*((int *)((*stacka)->content)) <= ps->quadrets[i] || (*stacka)->next == NULL)
		{
			ps_pa(stacka, stackb, ps);
			printlists(*stacka, *stackb);
		}
		else if ((*stacka)->next != NULL && j++)
		{
			ps_ra(stacka, stackb, ps);
			printlists(*stacka, *stackb);
		}
		if (j == countnodes(*stacka) && i++ < 4)
			j = 0;
	}
	return (*stacka);
}
