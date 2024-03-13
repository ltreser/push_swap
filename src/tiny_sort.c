/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:32:16 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/13 01:28:14 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_moves(long nbr, long i, int level_depth, t_tiny *tiny)
{
	long	res;
	int		counter;

	counter = level_depth;
	res = 0;
	while (nbr >= 4)
	{
		res = (res * 10) + (nbr % 4) + 1;
		counter--;
		nbr = nbr / 4;
	}
	res = (res * 10) + (nbr % 4) + 1;
	counter--;
	while (counter)
	{
		res = (res * 10) + 1;
		counter--;
	}
	tiny->moves[i] = res;
}

void	tiny_ops(t_deque *a, t_deque *b, long move, int print)
{
	if (move == 1 && print)
		sa(a, "sa");
	else if (move == 1 && !print)
		sa(a, "");
	else if (move == 2 && print)
		ra(a, 1, "ra");
	else if (move == 2 && !print)
		ra(a, 1, "");
	else if (move == 3 && print)
		pb(a, b, "pb");
	else if (move == 3 && !print)
		pb(a, b, "");
	else if (move == 4 && print)
		pa(b, a, "pa");
	else if (move == 4 && !print)
		pa(b, a, "");
	else
		return ;
}

long	check_level(t_all *all, long width, long depth, long move)
{
	long	i;
	long	j;

	i = -1;
	while (++i < width)
	{
		j = -1;
		move = all->tiny->moves[i];
		check_level_init(all);
		while (++j < depth && (tiny_ops(all->tiny->cpy_a, all->tiny->cpy_b,
					(move % 10), 0), 1))
			move /= 10;
		move = all->tiny->moves[i];
		if (stack_sorted(all->tiny->cpy_a))
			return (free_deque(all->tiny->cpy_a), free(all->tiny->cpy_b), move);
		else
		{
			if (all->tiny->cpy_b->size)
				free_deque(all->tiny->cpy_b);
			else
				free(all->tiny->cpy_b);
			free_deque(all->tiny->cpy_a);
		}
	}
	return (0);
}

void	exec_tiny(t_deque *a, t_deque *b, long moves)
{
	while (moves)
	{
		tiny_ops(a, b, (moves % 10), 1);
		moves /= 10;
	}
}

int	tiny_sort(t_all *all)
{
	long	i;
	long	level_width;
	long	level_depth;

	all->tiny = malloc(sizeof(t_tiny));
	level_depth = 0;
	level_width = 1;
	all->tiny->ideal_moves = 0;
	while (++level_depth < 15 && (!all->tiny->ideal_moves))
	{
		level_width *= 4;
		all->tiny->moves = malloc(level_width * sizeof(long));
		i = 0;
		while (i < level_width)
		{
			calculate_moves(i, i, level_depth, all->tiny);
			i++;
		}
		all->tiny->ideal_moves = check_level(all, level_width, level_depth, 0);
		free(all->tiny->moves);
	}
	exec_tiny(all->a, all->b, all->tiny->ideal_moves);
	return (free(all->tiny), 0);
}
