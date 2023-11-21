/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:05:21 by ghwa              #+#    #+#             */
/*   Updated: 2023/11/21 12:43:19 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"

typedef struct s_ps {
	int		argc;
	char	**argv;
	int		itemcount;
}	t_ps;

int		checkinputs(t_ps *ps, int argc, char **argv);
int		initall(t_ps *ps, int argc, char **argv);
int		initlinkedlist(t_ps *ps, t_list **stacka);

#endif