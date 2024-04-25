/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:03:55 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/09 19:52:50 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	save_fd(int *fd, int prev_fd)
{
	if (prev_fd != -1)
		close(prev_fd);
	close(fd[1]);
	prev_fd = fd[0];
	return (prev_fd);
}

void	wait_child(int n, int ac)
{
	int	j;

	j = n;
	while (j < ac - 1)
	{
		wait(NULL);
		j++;
	}
}

void	close_fd(int *fd, int prev_fd)
{
	close(fd[0]);
	close(fd[1]);
	close(prev_fd);
}

void	free_tab(char **tab)
{
	int	i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
