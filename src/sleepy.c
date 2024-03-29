/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleepy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 05:40:23 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/13 00:48:21 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ideal_lis(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->a->size)
	{
		find_lis(all->lis, all->a->size_total, 1, 0);
		rotate_array(all->lis->array, all->a->size, 1);
		i++;
	}
}

void	put_to_sleep(t_deque *a, t_row *lis, int lis_len)
{
	int		i;
	int		j;
	t_node	*travel;

	i = 0;
	j = 0;
	travel = a->head;
	if (lis_len < 500 && lis_len < lis->count)
		lis->count = lis_len;
	while (j < a->size)
	{
		i = 0;
		while (i < lis->count)
		{
			if (lis_len && travel->value == lis->lis[i] && lis_len--)
				travel->sleep = 1;
			i++;
		}
		travel = travel->next;
		j++;
	}
	a->sleep_count += lis->count;
}
