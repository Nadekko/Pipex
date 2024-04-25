/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:48:26 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/23 17:16:16 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	next_line = NULL;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = malloc(sizeof(char) * (ft_strlen_gnl(buffer) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*stock[FD_MAX] = {NULL};
	char		*buffer;
	char		*line;
	int			bytes_read;

	line = NULL;
	buffer = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr_gnl(stock[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stock[fd] = ft_strjoin_gnl(stock[fd], buffer);
	}
	free(buffer);
	if (bytes_read == -1 || !stock[fd])
		return (NULL);
	line = ft_get_line(stock[fd]);
	stock[fd] = ft_next_line(stock[fd]);
	return (line);
}
