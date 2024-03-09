/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:19:21 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/05 23:49:55 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_links(t_deque *a, char *name, char *stack)
{
	t_node	*temp_cw;
	t_node	*temp_ccw;
	int	i;
	int	cw;
	int	ccw;

	if (a->size == 0 && a->head)
		return (printf("empty stack is wrong\n"));
	if (a->size == 0 && !a->head)
		return(1);
	if (a->size == 1)
		return(1);
	i = -1;
	printf("size of %s after operation %s is %d\n", stack, name, a->size);
	print_deque(a);
	while (++i <= a->size)
	{
		cw = i;
		ccw = a->size - i;
		temp_cw = a->head;
		while (cw && cw--)
			temp_cw = temp_cw->next;
		temp_ccw = a->head;
		while (ccw && ccw--)
			temp_ccw = temp_ccw->prev;
		if (temp_cw->value != temp_ccw->value)
			exit (printf("operation %s is wrong!\n", name));
	}
	return (printf("nah this one is fine\n"), 1);
}

char	ra(t_deque *a, int times, char *print_flag)
{
	if (!a)
		return ('0');
	if (!a->size || a->size < 2)
		return ('0');
	while (times && times--)
	{
		a->tail = a->head;
		a->head = a->tail->next;
		//check_links(a, "ra", "a");
		print_moves(print_flag);
	}
	return ('4');
	//printf("a->head: %ld\n", a->head->value);
}

char	rb(t_deque *b, int times, char *print_flag)
{
	if (!b)
		return ('0');
	while (times && times--)
	{
		b->tail = b->head;
		b->head = b->tail->next;
		//check_links(b, "rb", "b");
		print_moves(print_flag);
	}
	return ('5');
	//printf("b->head: %ld\n", b->head->value);
}

char	rr(t_deque *a, t_deque *b, int times, char *print_flag)
{
	while (times && times--)
	{
		if (a)
		{
			a->tail = a->head;
			a->head = a->tail->next;
		}
		if (b)
		{
			b->tail = b->head;
			b->head = b->tail->next;
		}
		//check_links(a, "rr", "a");
		//check_links(b, "rr", "b");
		print_moves(print_flag);
	}
	return ('6');
	//printf("a->head: %ld\n", a->head->value);
	//printf("b->head: %ld\n", b->head->value);
}

char	rra(t_deque *a, int times, char *print_flag)
{
	if (!a)
		return ('0');
	while (times && times--)
	{
		a->head = a->tail;
		a->tail = a->tail->prev;
		//check_links(a, "rra", "a");
		print_moves(print_flag);
	}
	return ('7');
}

char	rrb(t_deque *b, int times, char *print_flag)
{
	if (!b)
		return ('0');
	while (times && times--)
	{
		b->head = b->tail;
		b->tail = b->tail->prev;
		//check_links(b, "rrb", "b");
		print_moves(print_flag);
	}
	return ('8');
	//printf("b->head: %ld\n", b->head->value);
}

