/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:54:18 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/12 09:29:55 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimizer_extension(char *ins, int i)
{
	if (ins[i] == '4' && ins[i + 1] == 'B' && ins[i + 2] == '7')
	{
		ins[i] = '1';
		ins[i + 1] = 'B';
		ins[i + 2] = '0';
	}
	if (ins[i] == '5' && ins[i + 1] == 'A' && ins[i + 2] == '8')
	{
		ins[i] = '2';
		ins[i + 1] = 'A';
		ins[i + 2] = '0';
	}
}

void	post_optimizer(t_all *all)
{
	int	i;

	i = -1;
	while (all->new_ins[++i])
	{
		if ((all->new_ins[i] == '1' && all->new_ins[i + 1] == '2')
			|| (all->new_ins[i] == '2' && all->new_ins[i + 1] == '1'))
		{
			all->new_ins[i] = '3';
			all->new_ins[i + 1] = '0';
		}
		if ((all->new_ins[i] == '4' && all->new_ins[i + 1] == '5')
			|| (all->new_ins[i] == '5' && all->new_ins[i + 1] == '4'))
		{
			all->new_ins[i] = '6';
			all->new_ins[i + 1] = '0';
		}
		if ((all->new_ins[i] == '7' && all->new_ins[i + 1] == '8')
			|| (all->new_ins[i] == '8' && all->new_ins[i + 1] == '7'))
		{
			all->new_ins[i] = '9';
			all->new_ins[i + 1] = '0';
		}
		optimizer_extension(all->new_ins, i);
	}
}

void	check_best_moves(t_all *all)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	post_optimizer(all);
	while (all->new_ins[++i])
		if (all->new_ins[i] != '0')
			count++;
	i = 0;
	if (count < all->instruction_count)
	{
		if (all->instructions)
			free(all->instructions);
		all->instruction_count = count;
		all->instructions = malloc((count + 1) * sizeof(char));
		while (all->new_ins[++j])
			if (all->new_ins[j] != '0')
				all->instructions[i++] = all->new_ins[j];
		all->instructions[i] = '\0';
	}
	free(all->new_ins);
	all->new_ins = ft_calloc(50000, sizeof(char));
}

void	decode_and_print(t_all *all, int i)
{
	while (all->instructions[++i])
	{
		if (all->instructions[i] == '1')
			write(1, "sa\n", 3);
		else if (all->instructions[i] == '2')
			write(1, "sb\n", 3);
		else if (all->instructions[i] == '3')
			write(1, "ss\n", 3);
		else if (all->instructions[i] == '4')
			write(1, "ra\n", 3);
		else if (all->instructions[i] == '5')
			write(1, "rb\n", 3);
		else if (all->instructions[i] == '6')
			write(1, "rr\n", 3);
		else if (all->instructions[i] == '7')
			write(1, "rra\n", 4);
		else if (all->instructions[i] == '8')
			write(1, "rrb\n", 4);
		else if (all->instructions[i] == '9')
			write(1, "rrr\n", 4);
		else if (all->instructions[i] == 'A')
			write(1, "pa\n", 3);
		else if (all->instructions[i] == 'B')
			write(1, "pb\n", 3);
	}
}
