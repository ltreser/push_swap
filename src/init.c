/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:12:31 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/10 04:42:16 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_all *all)
{
    all->a = malloc(sizeof(t_deque));
    all->a->head = NULL;
    all->b = malloc(sizeof(t_deque));
    all->lis = NULL;
	all->b->head = NULL;
	all->a->size = 0;
	all->new_ins = ft_calloc(50000, sizeof(char));
	if (!all->new_ins)
		free_all(all);
	all->instructions = NULL;
	all->instruction_count = 10000000;
	all->i = 0;
	//all->a_row->array = NULL;
	//all->a_row->sorted_copy = NULL;
}

