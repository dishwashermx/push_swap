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

void	pushintopos(t_list **stacka, t_list **stackb, t_ps *ps, int pos)
{
	int	i;

	i = 0;
	printf("pos %d\n", pos);
	if ((countnodes(*stacka) / 2) >= pos)
	{
		while (i++ < pos)
			ps_ra(stacka, stackb, ps);
	}
	else
	{
		while (i++ < pos)
			ps_rra(stacka, stackb, ps);
	}
	ps_pa(stacka, stackb, ps);
	if ((countnodes(*stacka) / 2) >= pos)
	{
		while (i-- > 1)
			ps_rra(stacka, stackb, ps);
	}
	else
	{
		while (i-- > 1)
			ps_ra(stacka, stackb, ps);
	}
	return ;
}
