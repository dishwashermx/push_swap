/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:17:34 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/08 14:04:05 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	error(char *error)
{
	ft_printf("ERROR\n");
	ft_printf("%s\n", error);
	return (0);
}

int	checknumber(t_ps *ps)
{
	int	i;

	i = 1;
	if (ps->argc < 1)
		return (0);
	while (ps->argv[i] != NULL)
	{
		if (ft_atoi(ps->argv[i]) == 0 && ft_strncmp(ps->argv[i], "0", \
		ft_strlen(ps->argv[i])) != 0)
			return (error("Argument is not a number"));
		if (ft_atol(ps->argv[i]) > 2147483647 \
		|| ft_atol(ps->argv[i]) < -2147483648)
			return (error("Argument is out of bounds"));
		ps->iargv[i - 1] = ft_atoi(ps->argv[i]);
		i++;
	}
	return (1);
}

int	checkrepeat(t_ps *ps)
{
	int	anchor;
	int	count;
	int	head;

	head = 0;
	while (head < ps->itemcount)
	{
		count = head;
		anchor = ps->iargv[head];
		while (++count < ps->itemcount)
		{
			if (anchor == ps->iargv[count])
				return (error("Repeated Number"));
		}
		head++;
	}
	return (1);
}

int	checkinputs(t_ps *ps)
{
	if (checknumber(ps) == 0)
		return (0);
	if (checkrepeat(ps) == 0)
		return (0);
	return (1);
}
