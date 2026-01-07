/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:45:47 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/07 15:13:17 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pab(t_stack *from, t_stack *to)
{
	int	i;
	
	to->size++;
	i = 1;
	while (to->array[i +1])
	{
		to->array[i] = to->array[i +1];
		i++;
	}
	to->array[0] = from->array[0];
	i = 0;
	while (from->array[i +1])
	{
		from->array[i] = from->array[i +1];
		i++;
	}
	from->size--;
}
