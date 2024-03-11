/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:19:21 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/11 07:54:24 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra2(t_all *all, int times, char *print_flag)
{
	if (!all->a)
		return ;
	if (!all->a->size || all->a->size < 2)
		return ;
	while (times && times--)
	{
		//check_swap(all);
		all->new_ins[all->i++] = '4';
		all->a->tail = all->a->head;
		all->a->head = all->a->tail->next;
		//check_links(a, "ra", "a");
		print_moves(print_flag);
	}
	//printf("a->head: %ld\n", a->head->value);
}

void	rb2(t_all *all, int times, char *print_flag)
{
	if (!all->b)
		return ;
	while (times && times--)
	{
		//check_swap(all);
		all->new_ins[all->i++] = '5';
		all->b->tail = all->b->head;
		all->b->head = all->b->tail->next;
		//check_links(b, "rb", "b");
		print_moves(print_flag);
	}
	//printf("b->head: %ld\n", b->head->value);
}

void	rr2(t_all *all, int times, char *print_flag)
{
	while (times && times--)
	{
		//check_swap(all);
		all->new_ins[all->i++] = '6';
		if (all->a)
		{
			all->a->tail = all->a->head;
        	all->a->head = all->a->tail->next;
		}
		if (all->b)
		{
			all->b->tail = all->b->head;
        	all->b->head = all->b->tail->next;
		}
		//check_links(a, "rr", "a");
		//check_links(b, "rr", "b");
		print_moves(print_flag);
	}
	//printf("a->head: %ld\n", a->head->value);
	//printf("b->head: %ld\n", b->head->value);
}

void	rra2(t_all *all, int times, char *print_flag)
{
	if (!all->a)
		return ;
	while (times && times--)
	{
		//check_swap(all);
		all->new_ins[all->i++] = '7';
		all->a->head = all->a->tail;
		all->a->tail = all->a->tail->prev;
		//check_links(a, "rra", "a");
		print_moves(print_flag);
	}
}

void	rrb2(t_all *all, int times, char *print_flag)
{
	if (!all->b)
		return ;
	while (times && times--)
	{
		//check_swap(all);
		all->new_ins[all->i++] = '8';
		all->b->head = all->b->tail;
		all->b->tail = all->b->tail->prev;
		//check_links(b, "rrb", "b");
		print_moves(print_flag);
	}
	//printf("b->head: %ld\n", b->head->value);
}

