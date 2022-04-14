#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

#define TYPE_PIPE 1
#define TYPE_BREAK 2
#define TYPE_END 3

#define STDIN 0
#define STDOUT 1

typedef struct s_list
{
	int type;
	int pipe[2];
	int lenght;
	char **args;
	struct s_list *next;
	struct	s_list *prev;

}	t_list;

t_list *ft_lstnew(int lenght, int type, char **args)
{
	t_list *new;
	int size = sizeof(t_list);

	new = malloc(size);
	new->type = type;
	new->pipe[0] = 0;
	new->pipe[1] = 0;
	new->lenght = lenght;
	new->args = args;
	new->next = NULL;
	new->prev = NULL;
}

void	ft_lstaddback(t_list **head, t_list *new)
{
	t_list *list = *head;

	if (!list)
	{
		list = new;
		return ;
	}
	while (list->next)
	{
		list = list->next;
	}
	list->next = new;
	new->prev = list;
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int i = 0;
	char *s2;
	int len = ft_strlen(str);
	
	s2 = malloc(len + 1);
	while (str[i])
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str , ft_strlen(str));
}

int is_sep(char *str)
{
	if (strcmp("|", str) == 0)
		return (TYPE_PIPE);
	else if (strcmp(";", str) == 0)
		return (TYPE_BREAK);
	return (0);
}

char **get_args(char **av, int index, int last_index)
{
	int i = 0;
	char **args;
	int diff = index- last_index;
	args = malloc(sizeof(char**) * (diff + 1));
	
	while (last_index < index)
	{
		args[i] = ft_strdup(av[last_index]);
		last_index++;
		i++;
	}
	args[diff] = NULL;
	return (args);
}

void exec_cmd(t_list *cmd, char **envp, t_list *head)
{
	int pid;
	int status;

	pipe(cmd->pipe);
	pid = fork();
	if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE)
		{
			dup2(cmd->pipe[1], STDOUT);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
		{
			dup2(cmd->prev->pipe[0], STDIN);
		}
		close(cmd->pipe[1]);
		close(cmd->pipe[0]);
		execve(cmd->args[0], cmd->args, envp);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(cmd->pipe[1]);
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipe[0]);
		if (cmd->type == TYPE_END || cmd->type == TYPE_BREAK)
			close(cmd->pipe[0]);
	}
}

void	exec_all(t_list *cmds, char **envp)
{
	t_list *head = cmds;
	while (cmds)
	{
		printf("yo");
		if(strcmp("cd", cmds->args[0]) == 0)
		{
			if (cmds->lenght != 2)
				ft_putstr_fd("error: cd bad arguments\n", 2);
			else if (chdir(cmds->args[1]))
			{
				ft_putstr_fd("error: cd cannot change dir\n", 2);
			}
		}
		else
			exec_cmd(cmds, envp , head);
		cmds = cmds->next;
	}
}

int main(int ac, char **av, char **envp)
{

	int i = 1;
	int last = 1;
	int type = 0;
	char **args;
	t_list *new = NULL;
	t_list *cmds = NULL;

	while (i < ac)
	{
		type = is_sep(av[i]);
		if (type)
		{
			args = get_args(av, i, last);
			new = ft_lstnew(i - last, type, args);
			ft_lstaddback(&cmds, new);
			last = i + 1;
		}
		type = 0;
		i++;
	}
	if (last !=ac)
	{
		args = get_args(av, i, last);
		new = ft_lstnew(i - last, TYPE_END, args);
		ft_lstaddback(&cmds, new);
	}
	exec_all(cmds, envp);
	

	


		

	return (0);
}
