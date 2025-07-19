#include "ft_malloc.h"

int qots_check(char *str)
{
	int i;
	char c;

	i = 0;
	while (!ft_isspace(str[i]) && (str[i] != '<' && str[i] != '>' && str[i] != '|'))
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			c = str[i++];
			while (c != str[i])
			{
				if (!str[i])
					return (c * -1);
				i++;
			}
			i++;
		}
		else
			i++;
	}
	return (i);
}

void syntax_qot_error(char qot)
{
	qot *= -1;
	ft_putstr_fd("minishell : syntax error unclosed qots by ", 2);
	ft_putchar_fd(qot, 2);
	ft_putchar_fd('\n', 2);
}

char *ft_copy(char *str, int *i, int size)
{
	char *dest;
	int j;

	dest = ft_malloc(size, SOME_LIST);
	if (!dest)
		return (perror("minishell"), ft_free_all(SOME_LIST), NULL);
	j = 0;
	while (j < size)
	{
		dest[j] = str[*i];
		(*i)++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int opperators_check(char *str)
{
    char c;
    int i;

    i = 0;
    c = str[i];
    while (c == str[i])
        i++;
    return (i);
}

void syntax_opp_error(char *str, int size)
{
    ft_putstr_fd("minishell : syntax error no such opperator ", 2);
    write(2, str, size);
    ft_putchar_fd('\n', 2);   
}

int word(char *str, t_shell **head)
{
	int i;
	int size;

	head = NULL;
	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i++]));
		if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		{
			size = opperators_check(str + i);
            if (size > 2)
                return (syntax_opp_error(str + i, size), -1);
		}
		else 
		{
			size = qots_check(str + i);
			if (size < 0)
				return (syntax_qot_error(size), -1);
		}
		if (!add_token_back(head, lst_new_token(ft_copy(str, &i, size + 1))))
			{
				printf("allo");
				return(-1);
				// return (lst_clear_token(*head), NULL);
			}
	}
    if (tokenization(*head) == -1)
	{
        return (ft_free_all(SOME_LIST), -1);
	}
	return(0);
}
