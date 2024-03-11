/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionss2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:01:42 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/11 07:54:33 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrr2(t_all *all, int times, char *print_flag)
{
	while (times && times--)
	{
		//check_swap(all);
		all->new_ins[all->i++] = '9';
		if (all->a)
			rra2(all, 1, "");
		if (all->b)
			rrb2(all, 1, "");
		//check_links(a, "rrr", "a");
		//check_links(b, "rrr", "b");
		print_moves(print_flag);
	}
	//printf("a->head: %ld\n", a->head->value);
	//printf("b->head: %ld\n", b->head->value);
}

