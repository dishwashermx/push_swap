/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:55:09 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/07 14:46:03 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	set_quadrants(t_ps *ps)
{
	int	*arr;
	int	quarter;
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr = bubblesort(ps);
	quarter = ps->itemcount / 4;
	printf("quarter = %d\n", quarter);
	while (i < ps->itemcount)
	{
		if (i % quarter == 0 && j < 3)
		{
			ps->quadrets[j] = arr[i];
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
	t_list	*head;

	set_quadrants(ps);
	head = *stacka;
	current = *stacka;
}
