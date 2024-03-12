/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divider_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 05:05:30 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 10:34:25 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divider_bf(t_all *all, int i)
{
	t_deque	*copy_a;
	int		lis_size[4];

	lis_size[0] = 10;
	lis_size[1] = 5;
	lis_size[2] = 500;
	lis_size[3] = 3;
	while (all->divider <= 2.7)
	{
		i = 0;
		while (i < 4)
		{
			all->i = 0;
			all->a->sleep_count = 0;
			copy_a = copy_deque(all->a);
			put_to_sleep(all->a, all->lis, lis_size[i++]);
			sleep_test(all, all->divider);
			back_to_a(all);
			check_best_moves(all);
			free_deque(all->a);
			all->a = copy_a;
		}
		all->divider += 0.031;
	}
	decode_and_print(all, -1);
}
