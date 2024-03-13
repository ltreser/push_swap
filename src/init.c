/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:12:31 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/13 01:40:04 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_all *all)
{
	all->a = malloc(sizeof(t_deque));
	all->a->head = NULL;
	all->b = malloc(sizeof(t_deque));
	all->lis = NULL;
	all->b->head = NULL;
	all->a->size = 0;
	all->new_ins = ft_calloc(15000, sizeof(char));
	if (!all->new_ins)
		free_all(all);
	all->instructions = NULL;
	all->instruction_count = 10000000;
	all->i = 0;
	all->a->sleep_count = 0;
}

int	non_numeric(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i] && av[i][j])
		{
			if (!j && (av[i][j] == '+' || av[i][j] == '-'))
				j++;
			else if (!ft_isdigit(av[i][j]))
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

void	check_level_init(t_all *all)
{
	all->tiny->cpy_a = copy_deque(all->a);
	all->tiny->cpy_b = malloc(sizeof(t_deque));
	all->tiny->cpy_b->size = 0;
	all->tiny->cpy_b->head = NULL;
}
