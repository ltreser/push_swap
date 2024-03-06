/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:31:54 by ltreser           #+#    #+#             */
/*   Updated: 2024/03/01 22:34:00 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_array(int *array, int size, int x)
{
	int	rotations;
	int	temp;
	int	i;

	if (size <= 1)
		return ;
	rotations = 0;
	while (rotations < x)
	{
		temp = array[size - 1];
		i = size - 1;
		while (i > 0)
		{
			array[i] = array[i - 1];
			i--;
		}
		array[0] = temp;
		rotations++;
	}
}
