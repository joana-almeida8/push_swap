/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_swaps1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:21 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/16 17:49:06 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	calc_cost_push_b(unsigned int index, t_stack *a, t_stack *b)
{
	if (index < a->size / 2)
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

void	pre_sort_b(int chunks_nbr, t_stack *a, t_stack *b)
{
	unsigned int	index;
	int				chunk;
	int				chunk_max;
	int				chunk_size;

	chunk = 1;
	chunk_size = a->size / chunks_nbr;
	while (a->size > 3)
	{
		index = 0;
		chunk_max = get_chunk_max(chunk, chunks_nbr, chunk_size, a);
		while (a->size > 3 && index < a->size)
		{
			if (a->array[index] <= chunk_max)
			{
				calc_cost_push_b(index, a, b);
				index = 0;
			}
			else
				index++;
		}
		chunk++;
	}
}

void	sort_tmp_array(int *tmp_array, int *input, int len)
{
	int	index;
	int	j;

	index = 0;
	while (index < len)
	{
		tmp_array[index] = input[index];
		index++;
	}
	index = 0;
	while (index < len - 1)
	{
		j = 0;
		while (j < len - index - 1)
		{
			if (tmp_array[j] > tmp_array[j + 1])
				ft_swap(&tmp_array[j], &tmp_array[j + 1]);
			j++;
		}
		index++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	big_swap(t_stack *a, t_stack *b)
{
	int	index;
	int	chunks_nbr;
	int	min_nbr_idx;

	index = 0;
	chunks_nbr = get_chunks_nbr(a);
	pre_sort_b(chunks_nbr, a, b);
	free(a->tmp_array);
	sort_3(a);
	turc_push_to_a(a, b);
	min_nbr_idx = smallest_nbr_index(a);
	if (min_nbr_idx < (int)a->size / 2)
	{
		while (min_nbr_idx-- > 0)
			rotate_a(a);
	}
	else
	{
		while (min_nbr_idx < (int)a->size)
		{
			reverse_a(a);
			min_nbr_idx++;
		}
	}
}
