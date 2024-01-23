/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:37:23 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/23 14:30:01 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	error(char *error)
{
	ft_printf("ERROR\n");
	ft_printf("%s\n", error);
	return (0);
}

void	freelst(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	freeall(t_list **stacka, t_list**stackb, t_ps *ps)
{
	freelst(stacka);
	freelst(stackb);
	free (ps->iargv);
	if (ps->itemcount > 50)
		free (ps->chunklets);
	ps->iargv = NULL;
	ps->chunklets = NULL;
	close (ps->fd);
	return ;
}

void	replace(char **str, t_ps *ps)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "rb", 2) == 0 && \
		ft_strncmp(str[i + 1], "ra", 2) == 0)
		{
			ft_putstr_fd("rr ", ps->fd);
			i++;
		}
		else if (ft_strncmp(str[i], "rrb", 3) == 0 && \
		ft_strncmp(str[i + 1], "rra", 3) == 0)
		{
			ft_putstr_fd("rrr ", ps->fd);
			i++;
		}
		else
		{
			ft_putstr_fd(str[i], ps->fd);
			ft_putchar_fd(' ', ps->fd);
		}
		i++;
	}
	ft_putstr_fd(str[i], ps->fd);
}

void	optops(t_ps *ps)
{
	char	*gnl;
	char	**str;
	int		i;

	i = 0;
	close (ps->fd);
	ps->fd = open("./temp", O_RDONLY);
	gnl = get_next_line(ps->fd);
	str = ft_split(gnl, ' ');
	close (ps->fd);
	ps->fd = open("./result", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	replace(str, ps);
	free (gnl);
	while (str[i] != NULL)
	{
		free (str[i]);
		i++;
	}
}
