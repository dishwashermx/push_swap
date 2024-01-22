/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:55:09 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/14 11:36:31 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	set_chunks(t_ps *ps, int chunks)
{
	int	*arr;
	int	chunksize;
	int	i;
	int	j;

	i = 1;
	j = 0;
	arr = bubblesort(ps);
	chunksize = ps->itemcount / chunks;
	printf("chunksize = %d\n", chunksize);
	while (i < ps->itemcount)
	{
		if (i % chunksize == 0 && j < (chunks - 1))
		{
			ps->chunklets[j] = arr[i + 1];
			printf("chunk %d is %d\n", j, i + 1);
			j++;
		}
		i++;
	}
	ps->chunklets[j] = arr[i - 1];
	free (arr);
}

t_list	*push_chunks(t_list **stacka, t_list **stackb, t_ps *ps, int chunks)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	set_chunks(ps, chunks);
	while (j < countnodes(*stacka))
	{
		if (countnodes(*stacka) == 3)
			return (*stacka);
		if (*((int *)((*stacka)->content)) <= ps->chunklets[i] \
		|| (*stacka)->next == NULL)
		{
			ps_pb(stacka, stackb, ps);
		}
		else if ((*stacka)->next != NULL && j++)
			ps_ra(stacka, stackb, ps);
		if (j == countnodes(*stacka) && i++ < chunks)
			j = 0;
	}
	return (*stacka);
}
