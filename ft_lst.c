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


void  *ft_lst_add_back(t_list **head, t_list *new)
{
  t_list *tmp;

  if (!head || !new)
    return (NULL);
  if (!*head)
  {
    *head = new;
    return (new);
  }
  tmp = *head;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  new->previous = tmp;
  new->next = NULL;
  return (tmp);
}
