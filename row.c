/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:41:05 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/01 22:22:47 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	safe_biggest_ascending(t_all *all, int divider)
{
	printf("row was better\n");
	int i;
	int j;
	int current;
	
	current = all->lis->start;
	i = 0;
	j = 0;
	
	if (all->lis->lis)
		free(all->lis->lis);
	all->lis->lis = malloc(all->lis->count * sizeof(int));
	all->lis->lis[j] = current;
	while(i < all->a->size && all->lis->array[i] != current)
		i++;
	while (i < all->a->size)
	{
		if (all->lis->array[i] > current && !(all->lis->array[i] > (current + (all->a->size / divider))))
		{
			j++;
			all->lis->lis[j] = all->lis->array[i];
			current = all->lis->array[i];
		}
		i++;
	}
}
			
void row_check_ascending(t_all *all)
{
	int i;
	int j;
	int current;
	int new_count;
	int divider;

	i = 0;
	current = 0;
	j = 0;
	new_count = 1;
	divider = 1;
	while (divider < 100)
	{
		i = 0;
		j = 0;
		while (j < all->a->size)
		{
			current = all->lis->array[j];
			while (i < all->a->size)
			{
				if (all->lis->array[i] > current && !(all->lis->array[i] > (current + (all->a->size / divider))))
				{		
					new_count++;
					current = all->lis->array[i];
				}
				i++;
			}
			if (new_count > all->lis->count)
			{
				all->lis->count = new_count;
				all->lis->start = all->lis->array[j];
				all->lis->end = current;
				safe_biggest_ascending(all, divider);
			}	
			j++;
			i = j;
			new_count = 1;
		}
		divider++;
	}
}

/*int	row_check_descending(t_row *numbers)
{
	int i;
	int j;
	int current;
	int new_count;

	numbers->count = 0;
	numbers->start = 0;
	i = 0;
	current = 0;
	j = 0;
	new_count = 1;
	while (j < numbers->n)
	{
		current = numbers->array[j];
		printf("%d: %d\n", j, (current));
		while (i < numbers->n)
		{
			if (numbers->array[i] < current && !(numbers->array[i] < (current / 3)))
			{		
				new_count++;
				current = numbers->array[i];
				printf("%d: %d\n", j, (current));
			}
			i++;
		}
		if (new_count > numbers->count)
		{
			numbers->count = new_count;
			numbers->start = numbers->array[j];
		}	
		j++;
		i = j;
		new_count = 1;
	}
	printf("start descending: %d\n", (numbers->start));	
			printf("count descending: %d\n", numbers->count);
	return (numbers->count);
}*/
