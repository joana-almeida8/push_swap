/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:45:36 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/12 16:18:54 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	str = malloc (count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, (count * size));
	return ((void *)str);
}
