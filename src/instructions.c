/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:19:21 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 09:34:48 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	check_links(t_deque *a, char *name, char *stack)
{
	t_node	*temp_cw;
	t_node	*temp_ccw;
	int		i;
	int		cw;
	int		ccw;

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
}*/
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
		print_moves(print_flag);
	}
	return ('4');
}

char	rb(t_deque *b, int times, char *print_flag)
{
	if (!b)
		return ('0');
	while (times && times--)
	{
		b->tail = b->head;
		b->head = b->tail->next;
		print_moves(print_flag);
	}
	return ('5');
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
		print_moves(print_flag);
	}
	return ('6');
}

char	rra(t_deque *a, int times, char *print_flag)
{
	if (!a)
		return ('0');
	while (times && times--)
	{
		a->head = a->tail;
		a->tail = a->tail->prev;
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
		print_moves(print_flag);
	}
	return ('8');
}
