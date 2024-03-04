/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleepy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:40:23 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/01 23:55:38 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_ideal_lis(t_all *all)
{
	int i;

	i = 0;
	//if (all->a->size->total > 999)
	//{
	//	find_lis(all->lis, all->a->size_total)
	//	return ;
	//}
	while (i < all->a->size) 
	{
		find_lis(all->lis, all->a->size_total);
		rotate_array(all->lis->array, all->a->size, 1);
		i++;
	}
	/*i = 0;
	while (i < all->lis->count)
	{
		printf("lis: %d\n", (all->lis->lis[i] + 1));
		i++;
	}*/
}

void put_to_sleep(t_deque *a, t_row *lis)
{
	int i;
	int j;

	i = 0;
	j = 0;
	t_node *travel;
	travel = a->head;
	while (j < a->size)
	{
		i = 0;
		while (i < lis->count)
		{
			if (travel->value == lis->lis[i])
				travel->sleep = 1;
			i++;
		}
		travel = travel->next;
		j++;
	}
}
