/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:30:38 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/06 01:42:13 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sleep_test(t_all *all, double divider)
{
	//int i;

	//i = (all->a->size_total / 2) + all->lis->count;
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
	while (all->a->size >= all->lis->count)
	{
		calculate_average(all->a, all->lis->count);
		//printf("average: %d\n", all->a->average);
		//exit (0);
		if (!all->a->head->sleep && all->a->head->value < all->a->average / divider)
		{
			all->new_ins[all->i++] = pb(all->a, all->b, "pb");
            all->new_ins[all->i++] = rb(all->b, 1, "rb");
		}
		else if (!all->a->head->sleep && all->a->head->value < all->a->average)
            all->new_ins[all->i++] = pb(all->a, all->b, "pb");
		else
			all->new_ins[all->i++] = ra(all->a, 1, "ra");
		/*else if ((all->a->size_total / 2) < all->a->size && all->a->head->value < ((all->a->size - all->lis->count) / 2))
			ra(all->a, 1, "ra");
		else if ((all->a->size_total / 2) < all->a->size && all->a->head->value > ((all->a->size - all->lis->count) / 2))
			pb(all->a, all->b, "pb");
		else if (all->a->size > all->a->size_total / 2 && all->a->head->value > all->a->size_total / 2)
		{
				pb(all->a, all->b, "pb");
				ra(all->a, 1, "ra");
		}
		else 
				pb(all->a, all->b, "pb");*/
		if (all->a->size == all->lis->count)
			break ;

	}

	/*printf("lis size: %d\n", all->lis->count);
	printf("a size before loop: %d\n", all->a->size);
	printf("b size before loop:: %d\n", all->b->size);
	while (all->b->size && all->a->size)
	{
		printf("size b in loop: %d\n", all->b->size);
		printf("size a in loop: %d\n", all->a->size);
		pa(all->b, all->a, "pa");
	}*/
}

void	push_swap(t_all *all)
{
	double divider;

	divider = 2.3;
	put_to_sleep(all->a, all->lis);
//	while (divider < 3)
//	{
	sleep_test(all, divider);
	back_to_a(all);
	//check_best_moves(all);
	//divider += 0.1;
//	}
	decode_and_print(all, -1);
	printf("operations: %d\n", all->instruction_count);
}
	


/*void	push_swap(t_all *all)
{
	put_to_sleep(all->a, all->lis);
	sleep_test(all);
	back_to_a(all);
	//stack_sorted(all->a);
	return ;
}*/
