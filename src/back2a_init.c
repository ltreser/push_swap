/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back2a_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:02:59 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/13 02:10:16 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_a(t_all *all)
{
	while (all->b->size)
	{
		put_index(all->a);
		put_index(all->b);
		if (all->b->size)
			set_target_pos(all, all->a->head, all->b->head, -1);
		calculate_price(all);
		push_to_a(all);
	}
	smallest_up(all);
}

void	put_index(t_deque *deque)
{
	int		i;
	t_node	*travel;

	if (!deque->size)
		return ;
	i = -1;
	travel = deque->head;
	deque->min = deque->head->value;
	deque->max = deque->head->value;
	deque->min_index = (deque->size - 1);
	deque->max_index = 0;
	while (++i < deque->size)
	{
		travel->index = i;
		travel->target_pos = -1;
		if (travel->value >= deque->max)
			(free(NULL), deque->max = travel->value, deque->max_index = i);
		if (travel->value <= deque->min)
			(free(NULL), deque->min = travel->value, deque->min_index = i);
		if (i >= (deque->size / 2))
			travel->lower_half = 1;
		else if (i < (deque->size / 2))
			travel->lower_half = 0;
		travel = travel->next;
	}
}

void	set_target_pos(t_all *all, t_node *i_a, t_node *i_b, int ib)
{
	int	target_node;
	int	ia;

	while (++ib < all->b->size)
	{
		(free(NULL), ia = -1, target_node = -1);
		while (++ia < all->a->size)
		{
			if (-1 == i_b->target_pos && i_a->value > i_b->value)
			{
				target_node = i_a->value;
				i_b->target_pos = i_a->index;
			}
			if (i_a->value > i_b->value && i_a->value < target_node)
			{
				i_b->target_pos = i_a->index;
				target_node = i_a->value;
			}
			i_a = i_a->next;
		}
		if (-1 == i_b->target_pos)
			i_b->target_pos = all->a->min_index;
		i_b = i_b->next;
	}
}

int	find_price(t_all *all, t_node *travel, int *dir, int mid_a)
{
	if (!travel->lower_half && travel->target_pos < mid_a && (*dir = 1, 1))
	{
		if (travel->index > travel->target_pos)
			travel->push_price = travel->index;
		else
			travel->push_price = travel->target_pos;
	}
	else if (travel->lower_half && travel->target_pos >= mid_a && (*dir = 2, 1))
	{
		if ((all->b->size - travel->index) > (all->a->size
				- travel->target_pos))
			travel->push_price = all->b->size - travel->index;
		else
			travel->push_price = all->a->size - travel->target_pos;
	}
	else
	{
		if (!travel->lower_half)
			travel->push_price = travel->index;
		if (travel->lower_half)
			travel->push_price = all->b->size - travel->index;
		if (travel->target_pos < (all->a->size / 2))
			travel->push_price += travel->target_pos;
		if (travel->target_pos >= (all->a->size / 2))
			travel->push_price += all->a->size - travel->target_pos;
	}
	return (travel->push_price);
}

void	calculate_price(t_all *all)
{
	int		i;
	int		dir;
	int		best_price;
	t_node	*travel;

	i = 0;
	best_price = 1000000;
	travel = all->b->head;
	while (i < all->b->size)
	{
		dir = 0;
		travel->push_price = find_price(all, travel, &dir, (all->a->size / 2));
		if (travel->push_price < best_price)
		{
			best_price = travel->push_price;
			all->b->cheapest_index = travel->index;
			all->b->cheapest_todo = dir;
		}
		travel = travel->next;
		i++;
	}
}
