/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:38:23 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/09 05:03:10 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_swappies_below(t_deque *a, int *lis, int count)
{
	int i;
	int swap;
	t_node *travel;

	i = 0;
	travel = a->head;
	swap = 0;
	while (i < count)
	{
		while (travel->value != lis[i])
		{
			if (travel->value > lis[i] && travel->value < lis[i + 1])
			{
				travel->has_swap = 1;
				travel->swap_below = lis[i];
				swap = 1;
			}
			travel = travel->next;
		}
		if (swap && travel->value == lis[i])
			travel->has_swap = 1;
		swap = 0;
		i++;
	}
}

void	find_swappies_above(t_deque *a, int *lis, int count)
{
	int swap;
	int swap_below;
	t_node *travel;

	travel = a->tail;
	while (count--)
	{		
		while (travel->value != lis[count - 1])
		{
			if (!travel->has_swap && travel->value < lis[count - 1] && travel->value > lis[count - 2])
			{
				travel->has_swap = 1;
				swap_below = travel->value;
				swap = 1;
			}
			travel = travel->prev;
		}
		if (swap && travel->value == lis[count - 1])
		{
			travel->has_swap = 1;
			travel->swap_below = swap_below;
		}
		swap = 0;
		swap_below = -1;
	}
}

