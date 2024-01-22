/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:37:23 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/22 17:19:13 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void freelst(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	freeall(t_list **stacka, t_list**stackb, t_ps *ps)
{
	freelst(stacka);
	freelst(stackb);
	free (ps->iargv);
	free (ps->chunklets);
	ps->iargv = NULL;
	ps->chunklets = NULL;
	close (ps->fd);
	return ;
}