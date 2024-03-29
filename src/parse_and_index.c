/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:41:25 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/13 01:37:38 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int *copy, int size, int i, int j)
{
	int	temp;

	temp = 0;
	while (i++ < (size - 1))
	{
		j = 0;
		while (j < (size - 1))
		{
			if (copy[j] > copy[j + 1])
			{
				temp = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = temp;
			}
			j++;
		}
	}
	return (copy);
}

void	normalize_by_index(int size, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (all->lis->array[i] == all->lis->sorted_copy[j])
			{
				all->lis->array[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	duplicate_found(int *array, int n, int size)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (size--)
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}

static void	parse_init(t_all *all)
{
	all->lis = malloc(sizeof(t_row));
	if (!all->lis)
		return ;
	all->lis->lis = NULL;
	all->lis->len = NULL;
	all->lis->prev_index = NULL;
	all->lis->array = malloc(all->a->size * sizeof(int));
	if (!all->lis->array)
		return ;
	all->lis->count = 0;
	all->lis->start = 0;
	all->lis->sorted_copy = malloc(all->a->size * sizeof(int));
	if (!all->lis->sorted_copy)
		return ;
}

int	parse_and_index(char **av, t_all *all)
{
	int		i;
	long	n;

	i = 0;
	parse_init(all);
	while (av[i])
	{
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (write(1, "Error\n", 6), free_all(all), 0);
		if (duplicate_found(all->lis->array, (int)n, i) && write(1, "Error\n",
				6))
			free_all(all);
		all->lis->array[i] = (int)n;
		i++;
	}
	i = -1;
	while (++i < all->a->size)
		all->lis->sorted_copy[i] = all->lis->array[i];
	all->lis->sorted_copy = bubble_sort(all->lis->sorted_copy, all->a->size, 0,
			0);
	normalize_by_index(all->a->size, all);
	return (0);
}
