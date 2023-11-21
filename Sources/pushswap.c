/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:11:36 by ghwa              #+#    #+#             */
/*   Updated: 2023/11/21 12:42:11 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	t_list	*stacka;
	t_list	*stackb;
	t_list	*stackc;

	initall(&ps, argc, argv);
	checkinputs(&ps, argc, argv);
	insertinlinkedlist(&ps, &stacka);
	return (0);
}
