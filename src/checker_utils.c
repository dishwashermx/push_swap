/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:20:03 by ghwa              #+#    #+#             */
/*   Updated: 2024/01/24 10:54:05 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

int	getinput(t_ps *ps)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL || temp[0] == '\0' || temp[0] == '\n')
		{
			ft_printf("%s", ps->input);
			free (ps->input);
			free (temp);
			return (0);
		}
		if (ps->input == NULL)
			ps->input = ft_strdup(temp);
		else
			ps->input = ft_strjoin(ps->input, temp);
		free (temp);
	}
	return (0);
}
