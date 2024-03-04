/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:19:21 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/02 23:47:17 by ltreser          ###   ########.fr       */
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

void	ra(t_deque *a, int times, char *print_flag)
{
	if (!a)
		return ;
	if (!a->size || a->size < 2)
		return ;
	while (times && times--)
	{
		a->tail = a->head;
		a->head = a->tail->next;
		//check_links(a, "ra", "a");
		print_moves(print_flag);
	}
	//printf("a->head: %ld\n", a->head->value);
}

void	rb(t_deque *b, int times, char *print_flag)
{
	if (!b)
		return ;
	while (times && times--)
	{
		b->tail = b->head;
		b->head = b->tail->next;
		//check_links(b, "rb", "b");
		print_moves(print_flag);
	}
	//printf("b->head: %ld\n", b->head->value);
}

void	rr(t_deque *a, t_deque *b, int times, char *print_flag)
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
	//printf("a->head: %ld\n", a->head->value);
	//printf("b->head: %ld\n", b->head->value);
}

void	rra(t_deque *a, int times, char *print_flag)
{
	if (!a)
		return ;
	while (times && times--)
	{
		a->head = a->tail;
		a->tail = a->tail->prev;
		//check_links(a, "rra", "a");
		print_moves(print_flag);
	}
}

void	rrb(t_deque *b, int times, char *print_flag)
{
	if (!b)
		return ;
	while (times && times--)
	{
		b->head = b->tail;
		b->tail = b->tail->prev;
		//check_links(b, "rrb", "b");
		print_moves(print_flag);
	}
	//printf("b->head: %ld\n", b->head->value);
}

