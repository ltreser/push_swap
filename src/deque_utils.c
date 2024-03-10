/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:58:17 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/10 05:07:06 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_deque(t_deque *deque)
{
    int i;
    t_node  *travel;

    printf("size: %d\n", deque->size);
    if (!deque)
        return ;
    i = -1;
    travel = deque->head;
	//printf("print\n");
    while (++i < deque->size)
    {
        printf("node %d: %ld, ", i, travel->value);
        //printf("target_pos %d: %d\n", i, travel->target_pos);
		//printf("node %d: %ld ", i, travel->value);     
		//printf("address %p ", travel);
        //printf("prev %p ", travel->prev);
        //printf("nex %p\n", travel->next);
        travel = travel->next;
    }
    printf("\n");
	/*i = -1;
	printf("revprint\n");
	while (++i < deque->size)
    {
        printf("node %d: %ld\n", i, travel->value);
        printf("node %d: %ld ", i, travel->value);
        printf("address %p ", travel);
        printf("prev %p ", travel->prev);
        printf("nex %p\n", travel->next);
        travel = travel->prev;
    }*/
}

t_deque *copy_deque(t_deque *deque)
{
	int i;
	
	i = 0;
	t_deque *copy;
	t_node *travel;
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
	exit (0);
}

/*
t_deque *copy_deque(t_deque *deque)
{
    int i = 0;
    t_deque *copy = malloc(sizeof(t_deque)); // Allocate memory for the copy deque
    if (!copy)
        return NULL; // Handle allocation failure

    copy->head = NULL; // Ensure head is initialized to NULL
    copy->size = 0;    // Initialize size to 0
    copy->size_total = deque->size; // Initialize size_total to 0

    t_node *travel = deque->head;

    while (i < deque->size)
    {
        append_node(copy, travel->value);
        travel = travel->next;
        i++;
    }

    return copy;
}
*/
void	free_all(t_all *all)
{
	if (!all)
		return ;
	if (all->lis)
	{
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
		free(all->lis);
	}
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
	if (all->i)
	{
		free(all->instructions);
		free(all->new_ins);
	}
	free(all);
	exit (0);
}

void    free_deque(t_deque *deque)
{
    t_node  *head;
	t_node 	*tail;

	//print_deque(deque);
    if (!deque)
		return ;
	head = deque->head;
 	if (!head && (free(deque), 1))
		return ;
	tail = deque->head->prev;
	if (deque->size == 1 && (free(deque), free(head), 1))
		return ;
	//printf("deque-size: %d\n", deque->size);
	//write(1, "executing free_deque\n", 21);
    while (head != tail)
	{	
		//write(1, "free loop\n", 10);
		//print_deque(deque);
		head = head->next;
		//printf("head: %p\n", head);
		free(head->prev);
		//head->prev = NULL;
   		//printf("head: %p _ head_next: %p _head_prev: %p tail: %p _ tail_next: %p tail_prev: %p\n", head, head->next, head->prev, tail, tail->next, tail->prev);
	}
	free(tail);
    free(deque);
}

void	calculate_average(t_deque *deque, int lis_size)
{
	t_node *travel;
	int 	i;
	int 	sum;

	travel = deque->head;
	i = 0;
	sum = 0;
	while (i < deque->size)
	{
		if(!deque->head->sleep)
			sum += travel->value;
		travel = travel->next;
		i++;
	}
	if (deque->size - lis_size == 0)
		deque->average = (sum / (deque->size - lis_size + 1));
	else
		deque->average = (sum / (deque->size - lis_size));
}
