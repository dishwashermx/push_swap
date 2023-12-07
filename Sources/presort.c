/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:55:09 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/07 17:19:03 by ghwa             ###   ########.fr       */
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
			ps->quadrets[j] = arr[i - 1];
			printf("quadret %d: %d\n", j, ps->quadrets[j]);
			j++;
		}
		i++;
	}
	ps->quadrets[j] = arr[i - 1];
	printf("quadret %d: %d\n", j, ps->quadrets[j]);
}

void	push_quadrants(t_ps *ps, t_list **stacka, t_list **stackb)
{
	t_list	*current;
	int		i;

	i = 0;
	current = *stacka;
	set_quadrants(ps);
	while (i < ps->itemcount)
	{
		if (current->next == NULL)
			return (ps_pa(current, stackb));
		else if (current == NULL)
			return ;
		if ((current)->content <= ps->quadrets[i])
			ps_pa(current, stackb);
		else
			current = current->next;
		if (current->next == NULL)
	}
	head = *stacka;
	current = *stacka;
}
