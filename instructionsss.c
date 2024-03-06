/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructionsss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:11:22 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/05 23:29:43 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_p(t_deque *a, t_deque *b)
{
	if (0 == b->size)
    {
		a->tail->next = a->head->next;
		a->head->next->prev = a->tail;
		b->head = a->head;
		b->head->next = b->head;
		b->head->prev = b->head;
		a->head = a->tail->next;
		b->tail = b->head;
		b->tail->next = b->head->next;
		b->tail->prev = b->head->prev;
    }
}

char pb(t_deque *a, t_deque *b, char *print_flag)
{
	if (a->size < 1)
		return ('0');
	if (b->size < 1)
		init_p(a, b);
	else if (1 == a->size)
		push_last(a, b);
	else if (a->size > 1)
	{
		a->tail->next = a->head->next;
		a->head->next->prev = a->tail;
		a->head->next = b->head;
		a->head->prev = b->tail;
		b->tail->next = a->head;
		b->head->prev = a->head;
		a->head = a->tail->next;
		b->head = b->tail->next;
	}
	a->size--;
	b->size++;
	//printf("b->size after pb: %d\n", b->size);
	//check_links(a, "pb", "a");
	//check_links(b, "pb", "b");
	print_moves(print_flag);
	return ('B');
}

void	push_last(t_deque *b, t_deque *a)
{
	//printf("enters push_last\n");
	a->tail->next = b->head;
	a->head->prev = b->head;
	b->head->next = a->head;
	b->head->prev = a->tail;
	a->head = b->head;
	b->head = NULL;
	b->tail = NULL;
}

char pa(t_deque *b, t_deque *a, char *print_flag)
{
	if (b->size < 1)
		return ('0');
	if (a->size < 1)
		init_p(b, a);
	else if (1 == b->size)
		push_last(b, a);
	else if (b->size > 1)
	{
		b->tail->next = b->head->next;
		b->head->next->prev = b->tail;
		b->head->next = a->head;
		b->head->prev = a->tail;
		a->tail->next = b->head;
		a->head->prev = b->head;
		b->head = b->tail->next;
		a->head = a->tail->next;
	}
	b->size--;
	a->size++;
	//printf("b->size: %d\n", b->size);
	//check_links(a, "pa", "a");
	//check_links(b, "pa", "b");
	print_moves(print_flag);
	return ('A');
}

void print_moves(char *print_flag)
{
	int i;

	i = 0;
	if (!print_flag[i]/* && all->size_total > 6*/)
		return ;
	/*if (!print_flag[i])
	{
		if (!all->new_ins)
		{
			all->new_ins = malloc(2 * sizeof(char));
			all->new_ins[i++] = identifier;
			all->new_ins[i] = '\0';
		}
		else 
			all->new_ins = ft_strjoin(all_new_ins, &identifier);
		all->new_ins_count++;
	}*/
	while (print_flag[i])
	{
		write(1, &print_flag[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
