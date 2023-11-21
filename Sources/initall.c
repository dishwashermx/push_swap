/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:23:56 by ghwa              #+#    #+#             */
/*   Updated: 2023/11/21 12:53:54 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	initall(t_ps *ps, int argc, char **argv)
{
	ps->argc = argc;
	ps->argv = argv;
	ps->itemcount = argc - 1;
	return (1);
}

int	initlinkedlist(t_ps *ps, t_list **stacka)
{
	printf("%d items\n", ps->itemcount);
	ft_lstnew(stacka -> content);
	return (0);
}
