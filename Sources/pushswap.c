/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:11:36 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 10:49:30 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	initall(&ps, argc, argv);
	if (checkinputs(&ps) == 0)
		return (0);
	initlinkedlist(&ps, &stacka);
	push_quadrants(&ps, &stacka, &stackb);
	return (0);
}
