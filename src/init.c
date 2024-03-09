/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:12:31 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/07 00:08:50 by ltreser          ###   ########.fr       */
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
	all->new_ins = ft_calloc(15000, 1);
	all->instructions = NULL;
	all->instruction_count = 10000000;
	all->i = 0;
	//all->a_row->array = NULL;
	//all->a_row->sorted_copy = NULL;
}

