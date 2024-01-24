/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:11:36 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 22:45:53 by ghwa             ###   ########.fr       */
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
	if (checkinputs(&ps, 0) == 0)
		return (freeall(&stacka, &stackb, &ps, 0));
	initlinkedlist(&ps, &stacka);
	if (countnodes(stacka) <= 50)
		smallsort(&ps, &stacka, &stackb);
	else
		bigsort(&stacka, &stackb, &ps);
	optops(&ps);
	freeall(&stacka, &stackb, &ps, 1);
	return (0);
}
