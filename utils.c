/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 04:09:03 by andjenna          #+#    #+#             */
/*   Updated: 2024/04/10 15:21:12 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

char	**get_env(char **envp, char **args)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			if (!path)
				msg_error("Error", "malloc failed");
			return (path);
		}
		i++;
	}
	if (!envp[i])
	{
		free_tab(args);
		msg_error("Error", "No environment variables");
	}
	return (NULL);
}

void	handle_backslash(char *cmd, char **envp, char **args)
{
	char	*full_path;

	full_path = ft_strdup(args[0]);
	if (access(full_path, F_OK) == 0)
	{
		if (execve(full_path, args, envp) == -1)
		{
			free_tab(args);
			free(full_path);
			msg_error("Error", strerror(errno));
		}
	}
	else
	{
		free(full_path);
		free_tab(args);
		msg_error("Command not found", cmd);
	}
}

void	handle_cmd(char *cmd, char **envp, char **env, char **args)
{
	char	*full_path;
	char	*tmp;
	char	**tmp_env;

	tmp_env = env;
	while (*env)
	{
		tmp = ft_strjoin(*env, "/");
		full_path = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (access(full_path, F_OK) == 0)
		{
			if (execve(full_path, args, envp) == -1)
			{
				exit_free(args, tmp_env, full_path);
				msg_error("Error", strerror(errno));
			}
		}
		free(full_path);
		env++;
	}
	free_tab(args);
	free_tab(tmp_env);
	msg_error("Command not found", cmd);
}

// vérifiez si elle a réussi ou non.Si elle réussit,
// le code qui suit ne doit pas être exécuté,
// car le processus enfant sera remplacé par le nouveau programme.
int	exec_command(char *cmd, char **envp)
{
	char	**args;
	char	**env;

	if (!cmd || !*cmd || !ft_strcmp(cmd, ".") || !ft_strcmp(cmd, " "))
		return (msg_error("Error", "not enough arguments"));
	args = ft_split(cmd, ' ');
	env = NULL;
	if (ft_strchr(cmd, '/'))
		handle_backslash(cmd, envp, args);
	else
	{
		env = get_env(envp, args);
		handle_cmd(cmd, envp, env, args);
	}
	free_tab(args);
	free_tab(env);
	return (0);
}
