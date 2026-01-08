/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:09:06 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/08 14:02:04 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_stack *a, t_stack *b, long *input)
{
	if (a)
		free(a);
	if (input)
		free(input);
	if (b)
	{
		if (b->array)
			free(b->array);
		free(b);
	}
}

void	*free_str(char *str)
{
	/* int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	} */
	free(str);
	return (NULL);
}

/* void	*free_array(long *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
} */

t_stack	*init_stack(t_stack *s, long *input, size_t len)
{
	long	*inputb;
	
	s = malloc(sizeof(t_stack));
	if (!s)
	{
		ft_printf("Error5\n");
		exit(1);
	}
	s->capacity = len;
	if (input)
	{
		s->size = len;
		s->array = input;
	}
	else
	{
		s->size = 0;
		inputb = malloc(len * sizeof(long));
		if (!inputb)
			return (NULL);
		s->array = inputb;
	}
	return (s);
}
