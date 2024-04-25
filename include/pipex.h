/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:57 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/10 15:20:25 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <errno.h>

/*					utils.c					*/
char	**get_env(char **envp, char **args);
int		exec_command(char *cmd, char **envp);
int		tab_len(char **tab);
int		get_here_doc(char **av);
void	free_tab(char **tab);

/*					utils2.c				*/
int		save_fd(int *fd, int prev_fd);
void	wait_child(int n, int ac);
void	close_fd(int *fd, int prev_fd);

/*					main.c					*/
int		msg_error(char *error, char *msg);
void	exit_free(char **s1, char **s2, char *s3);

/*					pipex.c					*/
int		pipex(int ac, char **av, char **envp);

/*					here_doc.c				*/
int		here_doc(int ac, char **av, char **envp);

#endif