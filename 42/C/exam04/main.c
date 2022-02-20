#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>


#define TYPE_PIPE 1
#define TYPE_BREAK 2
#define TYPE_END 3

#define CD_BADARGS "error: cd: bad arguments\n"


typedef struct s_list
{
	char **args;
	int pipe[2];
	int type;
	int lenght;
	struct s_list *next;
	struct s_list *prev; 
}	t_list;

t_list *ft_lstnew(int type, char **args)
{
	int size;
	t_list *list;

	size = sizeof(t_list);
	list = malloc(size);
	
	list->args = args;
	list->type = type;
	list->pipe[0] = 0;
	list->pipe[1] = 0;
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

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
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
		index++;
		i++;
	}
	args[diff] = NULL;
	return (args);
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
			new = ft_lstnew(type, args);
			ft_lstaddback(&cmds, new);
			last = i + 1; 
		}
		i++;
	}
	return  (0);
}
