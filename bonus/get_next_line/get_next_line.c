/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreis-de <jreis-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:02:12 by jreis-de          #+#    #+#             */
/*   Updated: 2026/01/21 16:47:16 by jreis-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../../include/push_swap.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > __FD_SETSIZE)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
				return (NULL);
			if (bytes_read == 0)
				return (line);
		}
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (NULL);
		ft_update_buffer(buffer);
		if (ft_strchr(line, '\n'))
			return (line);
	}
}
