/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:05:21 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/07 14:33:19 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_ps {
	int		argc;
	char	**argv;
	int		*iargv;
	int		itemcount;
	int		indexa;
	int		*quadrets;
}	t_ps;

int		initall(t_ps *ps, int argc, char **argv);
int		checkinputs(t_ps *ps);
void	initlinkedlist(t_ps *ps, t_list **stacka);
int		error(char *error);
void	printlists(t_list *stacka, t_list *stackb);
void	push_quadrants(t_ps *ps, t_list **stacka, t_list **stackb);
int		*bubblesort(t_ps *ps);
int		countnodes(t_list *stack);
void	ps_donothing(t_list **stack);
void	ps_swap(t_list **stack);
void	ps_sa(t_list **stacka, t_list **stackb);
void	ps_sb(t_list **stacka, t_list **stackb);
void	ps_ss(t_list **stacka, t_list **stackb);
void	ps_push(t_list **stacki, t_list **stacko);
void	ps_pa(t_list **stacka, t_list **stackb);
void	ps_pb(t_list **stacka, t_list **stackb);
void	ps_rotate(t_list **stack);
void	ps_ra(t_list **stacka, t_list **stackb);
void	ps_rb(t_list **stacka, t_list **stackb);
void	ps_rr(t_list **stacka, t_list **stackb);
void	ps_reverse_rotate(t_list **stack);
void	ps_rra(t_list **stacka, t_list **stackb);
void	ps_rrb(t_list **stacka, t_list **stackb);
void	ps_rrr(t_list **stacka, t_list **stackb);
#endif