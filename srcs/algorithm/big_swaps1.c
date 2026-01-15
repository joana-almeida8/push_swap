/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_swaps1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:21 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/15 15:32:10 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	calc_cost_push_b(unsigned int index, t_stack *a, t_stack *b)
{
	int	dif_start;
	int	dif_end;

	dif_start = index - 0;
	dif_end = a->size - index;
	if (dif_start < dif_end)
	{
		while (index > 0)
		{
			rotate_a(a);
			index--;
		}
		push_b(a, b);
	}
	else
	{
		while (index < a->size)
		{
			reverse_a(a);
			index++;
		}
		push_b(a, b);
	}
}

void	pre_sort_b(int *tmp_array, int chunk_size, int chunks_nbr, 
	t_stack *a, t_stack *b)
{
	unsigned int	index;
	int				chunk;
	int				chunk_min;
	int				chunk_max;

	index = 0;
	chunk = 1;
	while (index <= a->size && a->size > 3 && chunk <= chunks_nbr)
	{
		chunk_max = get_chunk_max(tmp_array, chunk, chunks_nbr, chunk_size, a);
		chunk_min = tmp_array[chunk_max - chunk_size];
		while (index < a->size)
		{
			if (a->array[index] <= tmp_array[chunk_max])
			{
				calc_cost_push_b(index, a, b);
				index = 0;
				if (b->array[0] <= tmp_array[chunk_max - ((chunk_max + chunk_min) / 2)])
					rotate_b(b);
			}
			else
				index++;
		}
		chunk++;
	}
}

int	get_chunks_nbr(t_stack *a)
{
	if (a->size <= 10)
		return (5);
	else if (a->size <= 100)
		return (16);
	else
		return (35);
}

void	sort_tmp_array(int *tmp_array, t_stack *a)
{
	unsigned int	index;
	unsigned int	j;

	index = 0;
	while (index < a->size)
	{
		tmp_array[index] = a->array[index];
		index++;
	}
	index = 0;
    while (index < a->size - 1)
    {
        j = 0;
        while (j < a->size - index - 1)
        {
            if (tmp_array[j] > tmp_array[j + 1])
				ft_swap(tmp_array[j], tmp_array[j + 1]);
            j++;
        }
        index++;
    }
}

int	big_swap(t_stack *a, t_stack *b)
{
	int	index;
	int	chunks_nbr;
	int	chunk_size;
	int	*tmp_array;

	index = 0;
	tmp_array = malloc(a->size * sizeof(int));
	if (!tmp_array)
		return (0);
	sort_tmp_array(tmp_array, a);
	chunks_nbr = get_chunks_nbr(a);
	chunk_size = a->size / chunks_nbr;
	pre_sort_b(tmp_array, chunk_size, chunks_nbr, a, b);
	free(tmp_array);
	sort_3(a);
	return (1);
}
