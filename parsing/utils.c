/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:09:06 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/07 11:43:23 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	*free_array(long **array)
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
}

t_stack	*init_stack(t_stack *a, long *input, size_t len)
{
	a = malloc(sizeof(t_stack));
	if (!a)
	{
		ft_printf("Error5\n");
		exit(1);
	}
	a->size = len;
	a->capacity = len;
	a->array = input;
	return (a);
}
