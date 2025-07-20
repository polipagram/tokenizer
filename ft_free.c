#include "ft_malloc.h"

void ft_free(void *ptr, int flag)
{
  t_list **head;
  t_list *tmp;

  head = ft_global(NULL, flag);
  tmp = *head;
  while (tmp && tmp->content != ptr)
    tmp = tmp->next;
  if (tmp->next && tmp->previous)
  {
    tmp->next->previous = tmp->previous;
    tmp->previous->next = tmp->next;
  }
  else if (tmp->previous)
  {
    tmp->previous->next = NULL;
  }
  else if (tmp->next)
    tmp->next->previous = NULL;
  free(tmp->content);
  free(tmp);
}

void ft_free_all(int flag)
{
  t_list *tmp;
  t_list **ptr;

  ptr = ft_global(NULL, flag);
  if (!ptr)
    return ;
  tmp = (*ptr)->next;
  while (*ptr)
  {
    if (tmp)
      tmp = tmp->next;
    free((*ptr)->content);
    free(*ptr);
    *ptr = tmp;
  }
  ft_global(NULL, flag * 2);
}

void  ft_clean_up(void)
{
  ft_free_all(ENV_LIST);
  ft_free_all(SOME_LIST);
}
