/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:54:16 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/20 18:54:16 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	bigsort(t_list **stacka, t_list **stackb, t_ps *ps)
{
	int	chunks;

	if (countnodes(*stacka) <= 100)
		chunks = 5;
	else
		chunks = 11;
	push_chunks(stacka, stackb, ps, chunks);
	smallsort(ps, stacka, stackb);
	findpos(stacka, stackb, ps);
	// pushintopos(stacka, stackb, ps);
}

void	findpos(t_list **stacka, t_list **stackb, t_ps *ps)
{
	t_list	*stacka2;
	t_list	*stackb2;

	stacka2 = *stacka;
	stackb2 = *stackb;
}