/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:22:24 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/16 18:02:11 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	operate_stacks(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			swap_a(a);
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		big_swap(a, b);
	return (1);
}

int	*init_tmp_array(int	*input, int len)
{
	int	*tmp_array;

	tmp_array = malloc(len * sizeof(int));
	if (!tmp_array)
		return (NULL);
	sort_tmp_array(tmp_array, input, len);
	return (tmp_array);
}

int	smallest_nbr_index(t_stack *a)
{
	unsigned int	i;
	int				min;
	unsigned int	min_pos;

	i = 0;
	min = a->array[0];
	min_pos = 0;
	while (i < a->size)
	{
		if (a->array[i] < min)
		{
			min = a->array[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

int	get_chunks_nbr(t_stack *a)
{
	if (a->size <= 100)
		return (1);
	else
		return (12);
}

int	get_chunk_max(int chunk, int chunks_nbr, int chunk_size, t_stack *a)
{
	int	chunk_max;
	int	tmp_array_size;

	chunk_max = 0;
	tmp_array_size = a->capacity;
	if (chunk < chunks_nbr)
		chunk_max = a->tmp_array[chunk * chunk_size];
	else if (chunk == chunks_nbr)
		chunk_max = a->tmp_array[tmp_array_size - 4];
	return (chunk_max);
}
