/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:30:38 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/02 23:27:41 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sleep_test(t_all *all)
{
	int i;

	i = 0;
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
		if (all->a->head->sleep)
			ra(all->a, 1, "ra");
		else
			pb(all->a, all->b, "pb");
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
	put_to_sleep(all->a, all->lis);
	sleep_test(all);
	back_to_a(all);
	return ;
}
