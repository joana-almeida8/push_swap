/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_swaps1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:09:21 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/13 15:36:57 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pre_sort_b(int *tmp_array, int chunk_size, t_stack *a, t_stack *b)
{
	
}

int	chunks_nbr(t_stack *a)
{
	if (a->size <= 100)
		return (5);
	else if (a->size <= 250)
		return (8);
	else if (a->size <= 500)
		return (12);
}

void	sort_tmp_array(int *tmp_array, t_stack *a)
{
	int	index;
	int	j;
	int	tmp;

	index = 0;
	while (++index < a->size)
		tmp_array[index] = a->array[index];
	index = 0;
    while (index < a->size - 1)
    {
        j = 0;
        while (j < a->size - index - 1)
        {
            if (tmp_array[j] > tmp_array[j + 1])
            {
                tmp = tmp_array[j];
                tmp_array[j] = tmp_array[j + 1];
                tmp_array[j + 1] = tmp;
            }
            j++;
        }
        index++;
    }
}

void	turk_swap(t_stack *a, t_stack *b)
{
	int	index;
	int	chunk_size;
	int	*tmp_array;

	index = 0;
	tmp_array = malloc(a->size * sizeof(int));
	if (!tmp_array)
		return (NULL);
	sort_tmp_array(tmp_array, a);
	chunk_size = a->size / chunks_nbr(a);	
	pre_sort_b(tmp_array, chunk_size, a, b); // push to b in chunks while calc costs
	sort_3(a);

	
// calc biggest number of each chunk
	
	/* median = find_median(a);
	chunk_nbr(a);
	while (index < a->size -3)
	{
		if (a->size <= 50)
		{
			if (a->array[index] <= median)
				push_b(a, b);
			else
			{
				push_b(a, b);
				reverse_b(b);
			}
		}
		else if (a->size <= 100)
		{
			
		}
	}
	
	calc_cost(a, b, find_biggest_nbr(b));
	push_b(a, b); */
}

// Calculate the cost for every number in Stack B to be moved 
// to its correct position in Stack A.

// Dynamic Selection: Sometimes a number at the bottom of Stack B is much 
// cheaper to move than one at the top because its target position in Stack A 
// is also near the bottom.

// Double Rotations: If both the number in B and its target in A are in the 
// top halves of their respective stacks, you can use rr to move both at once, 
// saving instructions.

/* Calculate the Median: Find the median value of the current elements in Stack A.

Push to B:
- If the number is larger than the median, push it to B (pb). It will naturally 
stay at the top.

- If the number is smaller than the median, push it to B (pb) and then 
immediately rotate B (rb). This moves the smaller number to the bottom. */