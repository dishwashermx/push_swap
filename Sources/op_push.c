/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:58:18 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/01 15:06:35 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	ps_push(t_list **stacki, t_list **stacko)
{
	t_list	*node;

	if (*stacki == NULL)
		return ;
	node = *stacki;
	*stacki = (*stacki)->next;
	node->next = *stacko;
	*stacko = node;
}

void	ps_pa(t_list **stacka, t_list **stackb)
{
	ps_push(stacka, stackb);
}

void	ps_pb(t_list **stacka, t_list **stackb)
{
	ps_push(stackb, stacka);
}