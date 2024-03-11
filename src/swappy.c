/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 03:38:23 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/10 07:01:57 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_swappies_below(t_deque *a, int *lis, int count)
{
	int i;
	int swap;
	t_node *travel;

	i = 0;
	swap = 0;
	travel = a->tail;
	while(travel->value != lis[count - 1])
		travel = travel->next;
	travel = travel->next;
	while (i < count)
	{
		while (travel->value != lis[i])
		{
			if (!swap && travel->value > lis[i] && travel->value < lis[i + 1])
			{
				travel->has_swap = 1;
				travel->swap_below = lis[i];
				swap = 1;
				a->sleep_count++;
			}
			travel = travel->next;
		}
		if (swap && travel->value == lis[i])
			travel->has_swap = 1;
		swap = 0;
		i++;
	}
}

void	find_swappies_above(t_deque *a, int *lis, int i)
{
	int swap;
	int swap_below;
	t_node *travel;

	travel = a->tail;
	while (i)
	{		
		while (travel->value != lis[i])
		{
			if (!travel->has_swap && travel->value < lis[i] && i && travel->value > lis[i - 1])
			{
				travel->has_swap = 1;
				swap_below = travel->value;
				swap = 1;
			}
			travel = travel->prev;
		}
		if (swap && travel->value == lis[i] && a->sleep_count++)
		{
			travel->has_swap = 1;
			travel->swap_below = swap_below;
		}
		swap = 0;
		swap_below = -1;
	}
}

void	check_swap(t_all *all)
{
	if (all->a->head->has_swap && all->a->head->next->has_swap && all->a->head->swap_below == all->a->head->next->value)
	{
		all->a->head->has_swap = 0;
		all->a->head->next->has_swap = 0;
		if (all->b->size > 2 && all->b->head->value < all->b->head->next->value)
			all->new_ins[all->i++] = ss(all->a, all->b, "");
		else 
		all->new_ins[all->i++] = sa(all->a, "");
	}

	else if (all->a->head->has_swap && all->a->tail->has_swap && all->a->tail->swap_below == all->a->head->value)
	{
		all->a->head->has_swap = 0;
		all->a->tail->has_swap = 0;
		all->new_ins[all->i++] = rra(all->a, 1, "");
		if (all->b->size > 2 && all->b->head->value < all->b->head->next->value)
            all->new_ins[all->i++] = ss(all->a, all->b, "");
        else
			all->new_ins[all->i++] = sa(all->a, "");
	}
}

