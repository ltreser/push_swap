/* ******************I******************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:25:28 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/05 21:44:24 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_deque *a)
{
	//printf("a size: %d\n", a->size);
	//printf("a size total: %d\n", a->size_total);
	if (!a || a->size < a->size_total)
		return (0);
	t_node *travel;
	int i;

	i = 0;
	travel = a->head;
	while (i < (a->size - 1))
	{
		//printf("comparing %ld and %ld\n", travel->value, travel->next->value);
		if (travel->value > travel->next->value)
			return (0);
		travel = travel->next;
		i++;
	}
	printf("FOUND SORTED!!!\n");
	return (1);
}

void	append_node(t_deque *a, int value)
{
	if (a->head)
	{
		a->tail = malloc(sizeof(*a->tail));
		if (!a->tail)
			return ;
		a->tail->value = value;
		a->tail->sleep = 0;
		a->tail->next = a->head;
		a->tail->prev = a->head->prev;
		a->head->prev->next = a->tail;
		a->head->prev = a->tail;
	}
	else
	{
		a->head = malloc(sizeof(*a->head));
		if (!a->head)
			return ;
		a->head->value = value;
		a->head->sleep = 0;
		a->head->next = a->head;
		a->head->prev = a->head;
	}
}

void create_stack(t_all *all, char **av, int  ac)
{
	int i;

	i = 0;
	all->a->size = ac;
	all->size_total = ac;
	all->a->size_total = ac;
	all->b->size_total = ac;
	all->b->size = 0;
	parse_and_index(av, all);
	get_ideal_lis(all);
	while (i < all->size_total)
	{
		append_node(all->a, all->lis->array[i]);
		i++;
	}
}

int	argument_error(int i, char **av, t_all *all, int j)
{
	if (i > 2147483647 && (free(all), 1))
		exit (0);
	if (1 == i && (free(all), 1))
		exit (0);
    if (2 == i && write(1, "already sorted\n", 14))
    {
		free(all);
		exit(0);
	}	
	i = 0;
	while (av[i] && (av[i][j]))
	{
		j = 0;
		while (av[i] && av[i][j])
		{
			if (!j && !(ft_isdigit(av[i][j]) || 
			(av[i][j] == '+' || av[i][j] == '-')))
				return (free(all), 1);
			if (j && !ft_isdigit(av[i][j]))
				return (free(all), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	if (argument_error(ac, av + 1, all, 0))
		return (0); //how to give error message?
	init(all);
	create_stack(all, av + 1, ac - 1);
	if (!stack_sorted(all->a))
	{
		if (all->size_total < 7)
			tiny_sort(all);
		else
			push_swap(all);
	}
	printf("lis size: %d\n", all->lis->count);
	free_all(all);
	return (0);
}
