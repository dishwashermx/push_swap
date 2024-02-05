/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:00:33 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/29 13:02:31 by ghwa             ###   ########.fr       */
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
	if (checkinputs(&ps, 1) == 0)
		return (freeall(&stacka, &stackb, &ps));
	initlinkedlist(&ps, &stacka);
	if (getinput(&ps, &stacka, &stackb) == 0)
		return (freeall(&stacka, &stackb, &ps));
	if (stacksorted(&stacka) == 1 || countnodes(stackb) > 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	freeall(&stacka, &stackb, &ps);
}

int	getinput(t_ps *ps, t_list **stacka, t_list **stackb)
{
	char	*temp;

	(void)ps;
	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			return ((void)free (temp), 1);
		if (checkcmd2(stacka, stackb, ps, temp) == 0 && \
		checkcmd1(stacka, stackb, ps, temp) == 0)
			return ((void)free (temp), error(0));
		free (temp);
	}
	return (1);
}

int	checkcmd1(t_list **stacka, t_list **stackb, t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "pa", 2) == 0)
		ps_pa(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		ps_pb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "ra", 2) == 0)
		ps_ra(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rb", 2) == 0)
		ps_rb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rr", 2) == 0)
		ps_rr(stacka, stackb, ps);
	else
		return (0);
	return (1);
}

int	checkcmd2(t_list **stacka, t_list **stackb, t_ps *ps, char *cmd)
{
	if (ft_strncmp(cmd, "rra", 3) == 0)
		ps_rra(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rrb", 3) == 0)
		ps_rrb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "rrr", 3) == 0)
		ps_rrr(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "sa", 2) == 0)
		ps_sa(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "sb", 2) == 0)
		ps_sb(stacka, stackb, ps);
	else if (ft_strncmp(cmd, "ss", 2) == 0)
		ps_ss(stacka, stackb, ps);
	else
		return (0);
	return (1);
}
