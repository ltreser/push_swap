/* ******************I******************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:25:28 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 23:53:49 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_deque *a)
{
	if (!a || a->size < a->size_total)
		return (0);
	t_node *travel;
	int i;

	i = 0;
	travel = a->head;
	while (i < (a->size - 1))
	{
		if (travel->value > travel->next->value)
			return (0);
		travel = travel->next;
		i++;
	}
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
		a->tail->has_swap = 0;
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
		a->head->has_swap = 0;
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

void	argument_check(int ac, char **av, t_all *all)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (non_numeric(av) || (ac == 2 && !av[0][0]))
	{
		write(1, "Error\n", 6);
		free(all);
		exit(0);
	}
	if ((ac == 2 || ac == 1) && (free(all), 1))
		exit (0);
}

int	main(int ac, char **av)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	argument_check(ac, av + 1, all);
	init(all);
	create_stack(all, av + 1, ac - 1);
	if (!stack_sorted(all->a))
	{
		if (all->size_total < 7)
			tiny_sort(all);
		else
			push_swap(all);
	}
	free_all(all);
	return (0);
}
