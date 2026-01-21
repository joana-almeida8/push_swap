/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:03:19 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/21 16:47:13 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../../include/push_swap.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len_total;
	size_t	i;
	size_t	j;

	len_total = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	str = malloc((len_total + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (i + j < len_total)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

void	ft_update_buffer(char *buffer)
{
	int	start;
	int	i;

	i = 0;
	start = ft_strlen_gnl(buffer);
	while (start + i < BUFFER_SIZE)
	{
		buffer[i] = buffer[start + i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}
