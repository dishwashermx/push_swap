/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:11:52 by ghwa              #+#    #+#             */
/*   Updated: 2023/12/07 14:16:24 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pushswap.h"

void	printlists(t_list *stacka, t_list *stackb)
{
	t_list	*head;

	head = stacka;
	ft_printf("Stack A: ");
	while (head != NULL)
	{
		ft_printf("%d -> ", *((int *)(head->content)));
		head = head->next;
	}
	printf("NULL\n");
	head = stackb;
	ft_printf("Stack B: ");
	while (head != NULL)
	{
		ft_printf("%d -> ", *((int *)(head->content)));
		head = head->next;
	}
	printf("NULL\n");
}

int	countnodes(t_list *stack)
{
	int			count;
	t_list		*current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}

int	*bubblesort(t_ps *ps)
{
	int	i;
	int	j;
	int	*arr;
	int	temp;

	i = 0;
	j = 0;
	arr = ps->iargv;
	while (i < ps->itemcount - 1)
	{
		j = 0;
		while (j < ps->itemcount - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}