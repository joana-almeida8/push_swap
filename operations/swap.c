/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:35:48 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/07 14:39:00 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sab(t_stack *s)
{
	int	*temp;

	if (s->size < 2)
		return ;
	temp = s->array[0];
	s->array[1] = s->array[1];
	s->array[1] = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	sab(a);
	sab(b);
}
















/* void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (stack_to == NULL)
		*stack_to = tmp;
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
} */