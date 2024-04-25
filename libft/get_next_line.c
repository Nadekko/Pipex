/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:24:01 by andjenna          #+#    #+#             */
/*   Updated: 2024/01/23 18:11:02 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	next_line = malloc(sizeof(char) * (ft_strlengnl(buffer) - i + 1));
	if (!next_line)
		return (NULL);
	i++;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd, int error)
{
	static char	*stock = NULL;
	char		*buffer;
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0))
		return (NULL);
	if (error == 2)
		return (free(stock), NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchrgnl(stock, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stock = ft_strjoingnl(stock, buffer);
	}
	free(buffer);
	if (bytes_read == -1 || !stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_next_line(stock);
	return (line);
}

/*char	*ft_read(int fd, char *stock)
{
	char	*buffer;
	int		bytes_read;

	buffer = NULL;
	buffer = malloc(sizeof(char) * MY_BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stock, '\n'))
	{
		bytes_read = read(fd, buffer, MY_BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	if (bytes_read == -1)
		return (NULL);
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || MY_BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	stock = ft_read(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_next_line(stock);
	if (!stock)
		return (stock);
	return (line);
}*/
