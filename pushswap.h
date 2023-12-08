/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:05:21 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 16:15:24 by ghwa             ###   ########.fr       */
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
	int		*quadrets;
	int		steps;
	char	**ops;
}	t_ps;

int		initall(t_ps *ps, int argc, char **argv);
int		checkinputs(t_ps *ps);
void	initlinkedlist(t_ps *ps, t_list **stacka);
int		error(char *error);
void	printlists(t_list *stacka, t_list *stackb);
t_list	*push_quadrants(t_ps *ps, t_list **stacka, t_list **stackb);
int		*bubblesort(t_ps *ps);
int		countnodes(t_list *stack);
void	add_ops(t_ps *ps, char *str);
void	print_ops(t_ps *ps);
void	ps_donothing(t_list **stack);
t_list	*ps_swap(t_list **stack);
t_list	*ps_sa(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_sb(t_list **stacka, t_list **stackb, t_ps *ps);
void	ps_ss(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_push(t_list **stacki, t_list **stacko);
t_list	*ps_pa(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_pb(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_rotate(t_list **stack);
t_list	*ps_ra(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_rb(t_list **stacka, t_list **stackb, t_ps *ps);
void	ps_rr(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_reverse_rotate(t_list **stack);
t_list	*ps_rra(t_list **stacka, t_list **stackb, t_ps *ps);
t_list	*ps_rrb(t_list **stacka, t_list **stackb, t_ps *ps);
void	ps_rrr(t_list **stacka, t_list **stackb, t_ps *ps);
#endif