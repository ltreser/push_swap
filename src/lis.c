/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:44:27 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 09:42:40 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	init_lis(t_row *lis, int size_a)
{
	int	i;

	i = 0;
	if (lis->count)
	{
		free(lis->len);
		free(lis->prev_index);
	}
	lis->len = malloc(size_a * sizeof(int));
	while (i < size_a)
		lis->len[i++] = 1;
	lis->prev_index = malloc(size_a * sizeof(int));
	i = 0;
	while (i < size_a)
		lis->prev_index[i++] = 0;
}

int	find_last(t_row *lis, int i, int j, int size)
{
	i = lis->len[0];
	j = 1;
	while (j < size)
	{
		if (lis->len[j] > lis->len[i])
			i = j;
		j++;
	}
	return (i);
}

int	get_lis(t_row *lis, int i)
{
	int	len;
	int	size_lis;

	len = lis->len[i] - 1;
	size_lis = lis->len[i];
	if (lis->count > size_lis)
		return (0);
	lis->count = size_lis;
	if (lis->count)
		free(lis->lis);
	lis->lis = malloc(size_lis * sizeof(int));
	lis->end = lis->array[i];
	while (size_lis--)
	{
		lis->lis[len] = lis->array[i];
		if (1 == size_lis)
			lis->start = lis->lis[len];
		len--;
		i = lis->prev_index[i];
	}
	return (0);
}

int	find_lis(t_row *lis, int size, int i, int j)
{
	init_lis(lis, size);
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (lis->array[j] < lis->array[i])
			{
				if ((lis->len[j] + 1) >= lis->len[i])
				{
					lis->len[i] = (lis->len[j] + 1);
					lis->prev_index[i] = j;
				}
			}
			j++;
		}
		i++;
	}
	i = find_last(lis, i, j, size);
	if (!get_lis(lis, i))
		return (0);
	return (1);
}
