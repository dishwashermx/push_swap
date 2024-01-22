/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:11:36 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/19 17:43:09 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	initall(&ps, argc, argv);
	if (checkinputs(&ps) == 0)
		return ((void)free(ps.iargv), 0);
	initlinkedlist(&ps, &stacka);
	printlists(stacka, stackb);
	if (countnodes(stacka) <= 10)
		smallsort(&ps, &stacka, &stackb);
	else
		bigsort(&stacka, &stackb, &ps);
	printlists(stacka, stackb);
	ft_printf("TOTAL STEPS: %d\n", ps.steps);
	freeall(&stacka, &stackb, &ps);
	return (0);
}
