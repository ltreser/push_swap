/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:30:38 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 10:24:32 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sleep_test(t_all *all, double divider)
{
	int	i;

	// double barrier;
	// barrier = 0;
	i = all->a->size_total;
	/*while (i < all->a->size)
	{
		printf("array: %d\n", all->lis->array[i]);
		i++;
	}
	i = 0;
	while (i < all->lis->count)
	{
		printf("lis: %d\n", all->lis->lis[i]);
		i++;
	}*/
	while (i--)
	{
		calculate_average(all->a, all->a->sleep_count);
		if (all->b->size && all->a->head->sleep && all->a->tail->sleep
            && all->b->head->value < all->a->head->value
            && all->b->head->value > all->a->tail->value)
        {
            all->new_ins[all->i++] = pa(all->b, all->a, "");
            all->new_ins[all->i++] = ra(all->a, 1, "");
            all->a->tail->sleep = 1;
            all->a->sleep_count++;
        }
		else if (!all->a->head->sleep && all->a->head->value < all->a->average / divider)
		{
			all->new_ins[all->i++] = pb(all->a, all->b, "");
			all->new_ins[all->i++] = rb(all->b, 1, "");
			// if (all->b->head->value < all->b->head->next->value)
			// all->new_ins[all->i++] = sb(all->b, "");
		}
		else if (!all->a->head->sleep && all->a->head->value < all->a->average)
		{
			all->new_ins[all->i++] = pb(all->a, all->b, "");
			// if (all->b->head->value < all->b->head->next->value)
			//	all->new_ins[all->i++] = sb(all->b, "");
		}
		else
			all->new_ins[all->i++] = ra(all->a, 1, "");
		if (all->a->size == all->a->sleep_count)
			break ;
	}
	while (all->a->size >= all->a->sleep_count)
	{
		calculate_average(all->a, all->a->sleep_count);
		if (all->b->size && all->a->head->sleep && all->a->tail->sleep
			&& all->b->head->value < all->a->head->value
			&& all->b->head->value > all->a->tail->value)
		{
			all->new_ins[all->i++] = pa(all->b, all->a, "");
			all->new_ins[all->i++] = ra(all->a, 1, "");
			all->a->tail->sleep = 1;
			all->a->sleep_count++;
		}
		else if (!all->a->head->sleep && 
				all->a->head->value < all->a->average && 
				(!(all->a->head->value > all->b->size * ((122 - divider * 10) / 100)) || ((all->a->size - all->a->sleep_count) < 12)))
		{
			all->new_ins[all->i++] = pb(all->a, all->b, "");
			all->new_ins[all->i++] = rb(all->b, 1, "");
			// if (all->b->head->value < all->b->head->next->value)
			// all->new_ins[all->i++] = sb(all->b, "");
		}
		else if (!all->a->head->sleep && (all->a->head->value < all->a->average || (all->a->size - all->a->sleep_count) < 12))
		{
			all->new_ins[all->i++] = pb(all->a, all->b, "");
			// if (all->b->head->value < all->b->head->next->value)
			//      all->new_ins[all->i++] = sb(all->b, "");
		}
		else
			all->new_ins[all->i++] = ra(all->a, 1, "");
		if (all->a->size == all->a->sleep_count)
			break ;
		// barrier += 0.3;
	}
}

void	push_swap(t_all *all)
{
	if (all->a->size_total < 700)
	{
		all->divider = 1.7;
		divider_bf(all, 0);
	}		
	else 
	{
		all->i = 0;
		all->a->sleep_count = 0;
		put_to_sleep(all->a, all->lis, 500);
		sleep_test(all, 2);
		back_to_a(all);
		check_best_moves(all);
		decode_and_print(all, -1);
	}
}
