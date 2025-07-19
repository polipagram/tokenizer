#include "ft_malloc.h"

t_list *ft_lstnew(void *ptr)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if(!new)
        return(NULL);
    new->content = ptr;
    new->next = NULL;
    new->previous = NULL;
    return(new);
}

void *ft_lstadd_front(t_list **head, t_list *new)
{
    if(!new)
        return (NULL);
    if(!*head)
    {
        *head = new;
        return (*head);
    }
    new->next = *head;   
    (*head)->previous = new;
    (*head) = (*head)->previous;
    return (*head);
}
