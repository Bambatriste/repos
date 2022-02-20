#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>


#define TYPE_PIPE 0
#define TYPE_BREAK 1
#define TYPE_END 2

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

t_list *ft_lstnew(int lenght)
{
	int size;
	t_list *list;

	size = sizeof(t_list);
	list = malloc(size);
	
	list->args = args;
	list->type = TYPE_END;
	list->pipe[0] = 0;
	list->pipe[1] = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	ft_lst_addback(t_list **list, t_list *new)
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



int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void exec_cmd(char *cmd)
{

}

void exec_cmds(t_list *cmds)
{

}



void	parse_args(t_list **cmds, char *arg)
{
	int is_pipe;	
	int is_coma;

	is_pipe = (strcmp("|", arg) == 0);
	is_coma = (strcmp(";", arg) == 0);

	if (!is_pipe && !is_coma)
		


	/*if (is_pipe)
		cmds->type = TYPE_PIPE;*/


	

}


int main(int ac, char **av, char **envp)
{
	int i = 1;
	t_list *cmds = NULL;

	while (i < ac)
	{
		if (av[i] == SEP)
		seps[j] = i;
	}

	return  (0);
}
