#include "ft_malloc.h"

void *lst_clear_token(t_list *head)
{
    if(!head)
        return(NULL);
    t_list *tmp;
    tmp = head->next;
    while (head)
    {
        if (tmp)
            tmp = tmp->next;
        free(head->content);
        free(head);
    }
}

t_shell *lst_new_token(char *str)
{
    t_shell *new;

    if (!str)
        return (NULL);
    new = ft_malloc(sizeof(t_list), SOME_LIST);
    if (!new)
        return (NULL);
    ft_memset(new, 0, sizeof(new));
    new->value = str;
    return (new);
}

void *add_token_back(t_shell **head, t_shell *new)
{
    t_shell *tmp;
    
    if (!new)
        return (NULL);
    if (!*head)
        return (*head = new, new);
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->previous = tmp;
    return (tmp);
}
