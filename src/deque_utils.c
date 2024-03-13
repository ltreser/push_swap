/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:58:17 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/13 00:47:23 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*copy_deque(t_deque *deque)
{
	int		i;
	t_deque	*copy;
	t_node	*travel;

	i = 0;
	copy = malloc(sizeof(t_deque));
	copy->head = NULL;
	travel = deque->head;
	while (i < deque->size)
	{
		append_node(copy, travel->value);
		travel = travel->next;
		i++;
	}
	copy->size = deque->size;
	copy->size_total = deque->size_total;
	return (copy);
	exit(0);
}

void	free_rest(t_all *all)
{
	if (all->b)
	{
		if (all->b->size)
			free_deque(all->b);
		else
			free(all->b);
	}
	if (all->a)
	{
		if (all->a->size)
			free_deque(all->a);
	}
}

void	free_all(t_all *all)
{
	if (!all)
		return ;
	if (all->lis->sorted_copy)
		free(all->lis->sorted_copy);
	if (all->lis->array)
		free(all->lis->array);
	if (all->lis->prev_index)
		free(all->lis->prev_index);
	if (all->lis->lis)
		free(all->lis->lis);
	if (all->lis->len)
		free(all->lis->len);
	if (all->lis)
		free(all->lis);
	free_rest(all);
	free(all->instructions);
	free(all->new_ins);
	free(all);
	exit(0);
}

void	free_deque(t_deque *deque)
{
	t_node	*head;
	t_node	*tail;

	if (!deque)
		return ;
	head = deque->head;
	if (!head && (free(deque), 1))
		return ;
	tail = deque->head->prev;
	if (deque->size == 1 && (free(deque), free(head), 1))
		return ;
	while (head != tail)
	{
		head = head->next;
		free(head->prev);
	}
	free(tail);
	free(deque);
}

void	calculate_average(t_deque *deque, int lis_size)
{
	t_node	*travel;
	int		i;
	int		sum;

	travel = deque->head;
	i = 0;
	sum = 0;
	while (i < deque->size)
	{
		if (!deque->head->sleep)
			sum += travel->value;
		travel = travel->next;
		i++;
	}
	if (deque->size - lis_size == 0)
		deque->average = (sum / (deque->size - lis_size + 1));
	else
		deque->average = (sum / (deque->size - lis_size));
}
