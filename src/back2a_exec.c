/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back2a_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 03:41:20 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 09:32:27 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	low_placement(t_all *all, t_node *travel)
{
	int	rot_a;
	int	rot_b;

	rot_a = all->a->size - travel->target_pos;
	rot_b = all->b->size - travel->index;
	all->i = ft_strlen(all->new_ins);
	while (rot_a && rot_b && rot_a-- && rot_b--)
		all->new_ins[all->i++] = rrr(all->a, all->b, 1, "");
	if (rot_b)
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], rrb(all->b, rot_b,
				""), rot_b);
	else if (rot_a)
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], rra(all->a, rot_a,
				""), rot_a);
	all->new_ins[ft_strlen(all->new_ins)] = pa(all->b, all->a, "");
}

void	high_placement(t_all *all, t_node *travel)
{
	all->i = ft_strlen(all->new_ins);
	while (travel->index && travel->target_pos && travel->index--
		&& travel->target_pos--)
		all->new_ins[all->i++] = rr(all->a, all->b, 1, "");
	if (travel->index)
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], rb(all->b,
				travel->index, ""), travel->index);
	else if (travel->target_pos)
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], ra(all->a,
				(travel->target_pos), ""), (travel->target_pos));
	all->new_ins[ft_strlen(all->new_ins)] = pa(all->b, all->a, "");
}

void	mixed_placement(t_all *all, t_node *travel)
{
	if (travel->lower_half)
	{
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], rrb(all->b,
				(all->b->size - travel->index), ""), all->b->size
			- travel->index);
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], ra(all->a,
				travel->target_pos, ""), travel->target_pos);
	}
	else
	{
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], rb(all->b,
				travel->index, ""), travel->index);
		ft_memset(&all->new_ins[ft_strlen(all->new_ins)], rra(all->a,
				(all->a->size - travel->target_pos), ""), all->a->size
			- travel->target_pos);
	}
	all->new_ins[ft_strlen(all->new_ins)] = pa(all->b, all->a, "");
}

void	push_to_a(t_all *all)
{
	int		i;
	t_node	*travel;

	i = 0;
	travel = all->b->head;
	while (i < all->b->cheapest_index)
	{
		travel = travel->next;
		i++;
	}
	if (!all->b->cheapest_todo)
		mixed_placement(all, travel);
	if (1 == all->b->cheapest_todo)
		high_placement(all, travel);
	if (2 == all->b->cheapest_todo)
		low_placement(all, travel);
}
