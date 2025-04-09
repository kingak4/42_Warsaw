/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:32:51 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/14 11:48:47 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_function(int exiter)
{
	if(exiter == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(0);
}
int		open_file(char *file, int n)
{
	int	open_rest;
	//char	*r;
	
	//r = malloc(100);
	
	open_rest = -1;
	if (!file)
		return (-1);
	if (n == 0)
		open_rest = open(file, O_RDONLY);
	if (n == 1)
		open_rest = open(file, O_CREAT | O_WRONLY , 0644);
	if (open_rest == -1)
	{
		perror("operation failed");
		return (-1);
	}
	//read(open_rest, r, 100);
	//printf("%s\n", r);
	return (open_rest);
}
void	free_tab(char **tab)
{
	size_t i;
	
	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
char	*my_getenv( char *name, char **envp)
{
	int		name_len;

	if (!name || !envp)
		return (NULL);
	name_len = ft_strlen(name);
	while (*envp)
	{
		if (ft_strncmp(*envp, name, name_len) == 0)
		{
			if ((*envp)[name_len] == '=')
			{
				return (*envp + name_len + 1);
			}
			envp++;
		}
	}
	return (NULL);
}
char	*get_path(char **envp)
{
	const char	*rest;
	int	i;
	char **d;
	
	i = 47;
	rest = my_getenv("PATH", envp);
	d = ft_split(rest, i);
	
	
}


int main(int argc, char **argv, char **env)
{
	my_getenv()
	return 0;
}