/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back2a_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:41:20 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/11 07:28:59 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	low_placement(t_all *all, t_node *travel)
{
	int rot_a;
	int rot_b;
	//printf("enters low placement\n");
	//printf("size->a: %d\n", all->a->size);
	rot_a = all->a->size - travel->target_pos;
	rot_b = all->b->size - travel->index;
	all->i = ft_strlen(all->new_ins);
	while (rot_a && rot_b && rot_a-- && rot_b--)
		rrr2(all, 1, "");
	if (rot_b)
		rrb2(all, rot_b, "");
	else if (rot_a)
	{
		//ft_printf("enters in low placement\n");
		//printf("all->a->size: %d\n", all->a->size);
                //printf("travel->target_pos: %d\n", travel->target_pos);
                //printf("amount of rra: %d\n", all->a->size - travel->target_pos);
		rra2(all, rot_a, "");
	}
	all->new_ins[ft_strlen(all->new_ins)] = pa(all->b, all->a, "");
}

void	high_placement(t_all *all, t_node *travel)
{
	//ft_printf("enters high placement \n");
	all->i = ft_strlen(all->new_ins);
	while (travel->index && travel->target_pos && travel->index-- && travel->target_pos--)
		rr2(all, 1, "");
	if (travel->index)
		rb2(all, travel->index, "");
	else if (travel->target_pos)
		ra2(all, travel->target_pos, "");
	all->new_ins[ft_strlen(all->new_ins)] = pa(all->b, all->a, "");
}

void	mixed_placement(t_all *all, t_node *travel)
{
	//ft_printf("enters mixed placement\n");
	if (travel->lower_half)
	{
		rrb2(all, (all->b->size - travel->index), "");
		ra2(all, travel->target_pos, "");
	}
	else
	{
		//printf("all->a->size: %d\n", all->a->size);
		//printf("travel->target_pos: %d\n", travel->target_pos);
		//printf("amount of rra: %d\n", all->a->size - travel->target_pos);
		rb2(all, travel->index, "");
		rra2(all, (all->a->size - travel->target_pos), "");
		//printf("enters in mixed placement\n");
	}
	all->new_ins[ft_strlen(all->new_ins)] = pa(all->b, all->a, "");
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
