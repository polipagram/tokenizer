#include "ft_malloc.h"

int main()
{
    char *input;
    t_shell *head;
    int ret;
    head = NULL;
    while(1)
    {
        input =  readline("minishell$> ");
        ret = word(input, &head);
    }

}