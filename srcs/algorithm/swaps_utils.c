/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:57:09 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/15 15:29:48 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	get_chunk_max(int *tmp_array, int chunk, int chunks_nbr, int chunk_size,
	t_stack *a)
{
	int	chunk_max;
	int	tmp_array_size;

	chunk_max = 0;
	tmp_array_size = a->capacity;		
	if (chunk < chunks_nbr)
		chunk_max = tmp_array[chunk * chunk_size];
	else if (chunk == chunks_nbr)
		chunk_max = tmp_array[tmp_array_size - 4];
	return (chunk_max);
}
