/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:01:42 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/02 23:19:42 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrr(t_deque *a, t_deque *b, int times, char *print_flag)
{
	while (times && times--)
	{
		if (a)
		{
			a->head = a->head->prev;
			a->tail = a->head->prev;
		}
		if (b)
		{
			b->head = b->head->prev;
			b->tail = b->head->prev;
		}
		//check_links(a, "rrr", "a");
		//check_links(b, "rrr", "b");
		print_moves(print_flag);
	}
}

void sa(t_deque *a, char *print_flag)
{
	if (!a || a->size == 1)
		return ;
	if (a->size == 2)
	{
		a->tail = a->head;
		a->head = a->head->next;
	}
	else if (a->size > 2)
	{
		a->head->next->next->prev = a->head;
		a->head->prev->next = a->head->next;
		a->head->next->prev = a->head->prev;	
		a->head->prev = a->head->next;
		a->head->next = a->head->next->next;
		a->head->prev->next = a->head;
		a->head = a->head->prev;
	}
	//check_links(a, "sa", "a");
	print_moves(print_flag);
}

void sb(t_deque *b, char *print_flag)
{
	if (!b)
		return ;
	if (b->head->next->next == b->head)
	{
		b->tail = b->head;
		b->head = b->head->next;
	}
	else
	{
		b->head->next->next->prev = b->head;
		b->head->prev->next = b->head->next;
		b->head->next->prev = b->head->prev;
		b->head->prev = b->head->next;
		b->head->next = b->head->next->next;
		b->head->prev->next = b->head;
		b->head = b->head->prev;
	}
	//check_links(b, "sb", "b");
	print_moves(print_flag);
}

void ss(t_deque *a, t_deque *b, char *print_flag)
{
	if (a)
		sa(a, print_flag);
	if (b)
		sb(b, print_flag);
	//check_links(a, "ss", "a");
	//check_links(b, "ss", "b");
	print_moves(print_flag);
}
