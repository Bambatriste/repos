#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define STDIN 0
#define STDOUT 1
#define TYPE_PIPE 1
#define TYPE_BREAK 2
#define TYPE_END 3

typedef struct s_list
{
	char **args;
	int pipe[2];
	int type;
	int lenght;
	struct s_list *next;
	struct s_list *prev; 
}	t_list;

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

t_list *ft_lstnew(int type, char **args, int lenght)
{
	int size;
	t_list *list;

	size = sizeof(t_list);
	list = malloc(size);
	
	list->args = args;
	list->type = type;
	list->pipe[0] = 0;
	list->pipe[1] = 0;
	list->lenght = lenght;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	ft_lstaddback(t_list **list, t_list *new)
{
	t_list *last = *list;

	if (*list == NULL)
	{
		*list = new;
		return;
	}
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	ft_free_lst(t_list *cmds)
{
	t_list *tmp;
	int i = 0;
	while (cmds)
	{ 
		tmp = cmds->next;
		while(cmds->args[i])
		{
			free(cmds->args[i]);
			i++;
		}
		i = 0;
		free(cmds->args);
		free(cmds);
		cmds = tmp;
	}
}

int is_sep(char *arg)
{
	if (strcmp(";", arg) == 0)
		return (TYPE_BREAK);
	else if (strcmp("|", arg) == 0)
	{
		return (TYPE_PIPE);
	}
	else
		return (0);
}

char	*ft_strdup(char *s1)
{
	char	*scpy;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	scpy = NULL;
	scpy = malloc(sizeof(char) * len + 1);
	if (!scpy)
		return (NULL);
	while (s1[i])
	{
		scpy[i] = (char)s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}

char **get_args(char **av, int index, int last_index)
{
	int i = 0;
	int diff = index - last_index;
	char **args = malloc(sizeof(char **) * (diff + 1));

	while (last_index < index)
	{
		args[i] = ft_strdup(av[last_index]);
		last_index++;
		i++;
	}
	args[diff] = NULL;
	return (args);
}

void	exec_cmd(t_list *cmd, char **envp, t_list *head)
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
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
		execve(cmd->args[0], cmd->args, envp);
		ft_putstr_fd("error: cannot execute ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_lst(head);
		exit(2);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(cmd->pipe[1]);
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->pipe[0]);
		if(cmd->type == TYPE_END || cmd->type == TYPE_BREAK)
			close(cmd->pipe[0]);
	}
}

void exec_all(t_list *cmds, char **envp)
{
	t_list *head = cmds;
	while (cmds)
	{
		if (strcmp("cd", cmds->args[0]) == 0)
		{
			if (cmds->lenght != 2)
			{
				ft_putstr_fd("error: cd: bad arguments\n", 2);
			}
			else if (chdir(cmds->args[1]))
			{
				ft_putstr_fd("error: cd: cannot change directory to ", 2);
				ft_putstr_fd(cmds->args[1], 2);
				ft_putstr_fd("\n", 2);
			}
		}
		else
			exec_cmd(cmds, envp, head);
		cmds = cmds->next;
	}
}

int main(int ac, char **av, char **envp)
{
	int i = 1;
	int last = 1;
	t_list *cmds = NULL;
	t_list *new;
	char **args;
	int type;

	while (i < ac)
	{
		type = is_sep(av[i]);
		if (type)
		{
			args = get_args(av, i, last);
			new = ft_lstnew(type, args, i - last);
			ft_lstaddback(&cmds, new);
			last = i + 1;
		}
		type = 0;
		i++;
	}
	if (last != ac)
	{
		args = get_args(av, i, last);
		new = ft_lstnew(TYPE_END, args, i - last);
		ft_lstaddback(&cmds, new);
	}
	exec_all(cmds, envp);
	ft_free_lst(cmds);
	return  (0);
}
