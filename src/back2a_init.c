/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back2a_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:02:59 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/07 02:07:44 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_a(t_all *all)
{
	t_node *travel;
	//int i;

	//i = 12;
	travel = all->a->head;
	while (all->b->size)
	{
		put_index(all->a);
		put_index(all->b);
		set_target_position(all);
		calculate_price(all);
		push_to_a(all);
	}
	put_index(all->a);
	if (all->a->head->value == 0)
		return ;
	while (1) //get right later
	{
		travel = travel->next;
		if (travel->value == 0)
			break ;
	}
	if (travel->lower_half)
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], rra(all->a, (all->a->size - travel->index), ""), (all->a->size - travel->index));
	else
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], ra(all->a, travel->index, ""), travel->index);
	//print_deque(all->a);
	//while (all->a->head->value > 0)
	//	ra(all->a, 1, "ra");
	
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
		if (travel->value >= deque->max && (deque->max_index = i, 1))
			deque->max = travel->value;
		if (travel->value <= deque->min && (deque->min_index = i, 1))
			deque->min = travel->value;
		if (i >= (deque->size / 2))
			travel->lower_half = 1;
		else if (i < (deque->size / 2))
			travel->lower_half = 0;
		travel = travel->next;
	}
}

void	set_target_position(t_all *all)
{

	/*printf("\n\n\n\n____NEXT NODE____\n");	
	printf("DEQUE A: ");
	print_deque(all->a);
	printf("DEQUE B: ");
	print_deque(all->b);*/
	int		target_node;
	int		ib;
	int		ia;
	t_node	*travel_a;
	t_node	*travel_b;

	if (!all->b->size) // later with swaps in case of sorted only with swaps, error here
		return ;
	ia = 0;
	ib = 0;
	travel_a = all->a->head;
	travel_b = all->b->head;
	target_node = -1;
	while (ib < all->b->size)
	{
		//printf("new node: %ld\n", travel_b->value);
		ia = 0;
		target_node = -1;
		//printf("target_pos should be -1 and is: %d\n", travel_b->target_pos);
		while (ia < all->a->size)
		{
			if (-1 == travel_b->target_pos && travel_a->value > travel_b->value)
			{
				target_node = travel_a->value;
				travel_b->target_pos = travel_a->index;
				//printf("target node for node %d is being set to: %d\n", ib, target_node);
				//printf("target pos for node %d is being set to: %d\n", ib, travel_b->target_pos);
			}
			if (travel_a->value > travel_b->value && travel_a->value < target_node)
			{
				travel_b->target_pos = travel_a->index;
				target_node = travel_a->value;
				//printf("target node for node %d is being set to: %d\n", ib, target_node);
				//printf("target pos for node %d is being set to: %d\n", ib, travel_b->target_pos);
			}
			travel_a = travel_a->next;
			ia++;
		}
		if (-1 == travel_b->target_pos)
		{
			travel_b->target_pos = all->a->min_index;
		//printf("target pos for node %d is being set to: %d\n", ib, travel_b->target_pos);
		}
		//printf("\n");
		travel_b = travel_b->next;
		ib++;
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
		if ((all->b->size - travel->index) > (all->a->size - travel->target_pos))
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
	int i;
	int dir;
	int best_price;
	t_node *travel;

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
