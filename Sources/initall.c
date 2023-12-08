/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:23:56 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 16:10:10 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	initall(t_ps *ps, int argc, char **argv)
{
	ps->argc = argc;
	ps->argv = argv;
	ps->itemcount = argc - 1;
	ps->iargv = malloc(ps->itemcount * sizeof(int) + 1);
	ps->steps = 0;
	return (1);
}

void	initlinkedlist(t_ps *ps, t_list **stack)
{
	int		i;

	i = 0;
	while (i < ps->argc - 1)
		ft_lstadd_back(stack, ft_lstnew(&ps->iargv[i++]));
}
