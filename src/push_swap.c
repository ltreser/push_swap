/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:30:38 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/07 06:25:45 by ltreser          ###   ########.fr       */
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
		if (!all->a->head->sleep && all->a->head->value < all->a->average / divider)
		{
			all->new_ins[all->i++] = pb(all->a, all->b, "");
        	all->new_ins[all->i++] = rb(all->b, 1, "");
			//if (all->b->head->value < all->b->head->next->value)
				//all->new_ins[all->i++] = sb(all->b, "");
		}
		else if (!all->a->head->sleep && all->a->head->value < all->a->average)
		{
			all->new_ins[all->i++] = pb(all->a, all->b, "");
			//if (all->b->head->value < all->b->head->next->value)
			//	all->new_ins[all->i++] = sb(all->b, "");
		}
		else
			all->new_ins[all->i++] = ra(all->a, 1, "");
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
	int i;
	t_deque *copy_a;

	i = -1;
	all->divider = 1.5;
	//copy_a = copy_deque(all->a);
	while (all->divider <= 3.1)
	{
		copy_a = copy_deque(all->a);
		put_to_sleep(all->a, all->lis);
		sleep_test(all, all->divider);
		back_to_a(all);
		check_best_moves(all);
		all->divider += 0.025;
		free_deque(all->a);
		all->a = copy_a;
	}
	//while (all->new_ins[++i])
	//	printf("new_ins[%d] = %c\n", i, all->new_ins[i]);
	decode_and_print(all, -1);
	//printf("operations: %d\n", all->instruction_count);
}
	

/*
void	push_swap(t_all *all)
{
	put_to_sleep(all->a, all->lis);
	sleep_test(all, 2.2);
	back_to_a(all);
	//stack_sorted(all->a);
	return ;
}*/
