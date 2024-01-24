/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:00:33 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 15:15:10 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	initall(&ps, argc, argv);
	if (checkinputs(&ps, 1) == 0)
		return ((void)free(ps.iargv), 0);
	getinput(&ps);
}

int	getinput(t_ps *ps)
{
	char	*temp;

	(void)ps;
	while (1)
	{
		temp = get_next_line(0);
		if (checkcmd(temp) == 0)
			return (error((char *)(NULL)));
		free (temp);
	}
	return (0);
}

int	checkcmd(char *cmd)
{
	if (strncmp(cmd, "rr", 2) == 0 || strncmp(cmd, "rr", 2) == 0)
	return (0);
}