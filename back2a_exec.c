/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back2a_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:41:20 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/02 23:52:48 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	low_placement(t_all *all, t_node *travel)
{
	int rot_a;
	int rot_b;

	//printf("size->a: %d\n", all->a->size);
	rot_a = all->a->size - travel->target_pos;
	rot_b = all->b->size - travel->index;
	while (rot_a && rot_b && rot_a-- && rot_b--)
		rrr(all->a, all->b, 1, "rrr");
	if (rot_b)
		rrb(all->b, rot_b, "rrb");
	else if (rot_a)
	{
		//printf("enters in low placement\n");
		//printf("all->a->size: %d\n", all->a->size);
                //printf("travel->target_pos: %d\n", travel->target_pos);
                //printf("amount of rra: %d\n", all->a->size - travel->target_pos);
		rra(all->a, rot_a, "rra");
	}
	pa(all->b, all->a, "pa");
}

void	high_placement(t_all *all, t_node *travel)
{
	while (travel->index && travel->target_pos && travel->index-- && travel->target_pos--)
		rr(all->a, all->b, 1, "rr");
	if (travel->index)
		rb(all->b, travel->index, "rb");
	else if (travel->target_pos)
		ra(all->a, travel->target_pos, "ra");
	pa(all->b, all->a, "pa");
}

void	mixed_placement(t_all *all, t_node *travel)
{
	if (travel->lower_half)
	{
		rrb(all->b, (all->b->size - travel->index), "rrb");
		ra(all->a, travel->target_pos, "ra");
	}
	else
	{
		//printf("all->a->size: %d\n", all->a->size);
		//printf("travel->target_pos: %d\n", travel->target_pos);
		//printf("amount of rra: %d\n", all->a->size - travel->target_pos);
		rb(all->b, travel->index, "rb");
		rra(all->a, (all->a->size - travel->target_pos), "rra");
		//printf("enters in mixed placement\n");
	}
	pa(all->b, all->a, "pa");
}

void	push_to_a(t_all *all)
{
	int i;
	t_node *travel;

	i = 0;
	travel = all->b->head;
	while (i < all->b->cheapest_index)
	{
		travel = travel->next;
		i++;
	}
	//printf("cheapest index: %d\n", all->b->cheapest_index);
	//printf("target position: %d\n", travel->target_pos);
	//printf("todo: %d\n", all->b->cheapest_todo);
	if (!all->b->cheapest_todo)
		mixed_placement(all, travel);
	if (1 == all->b->cheapest_todo)
		high_placement(all, travel);
	if (2 == all->b->cheapest_todo)
		low_placement(all, travel);
}
