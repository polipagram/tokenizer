#include "ft_malloc.h"

void ft_free(void *ptr, int flag)
{
  t_list *tmp;

  tmp = ft_global(NULL, flag);
  while (tmp->content != ptr)
    tmp = tmp->next;
  if (tmp->next && tmp->previous)
  {
    tmp->next->previous = tmp->previous;
    tmp->previous->next = tmp->next;
  }
  else
  {
    tmp->previous->next = NULL;
  }
  free(tmp->content);
  free(tmp);
}

void ft_free_all(int flag)
{
  t_list *tmp;
  t_list *ptr;

  ptr = ft_global(NULL, flag);
  if (!ptr)
    return ;
  tmp = ptr;
  while (tmp)
  {
    if (ptr)
      ptr = ptr->next;
    free(tmp->content);
    free(tmp);
    tmp = ptr;
  }
}

void  ft_clean_up(void)
{
  ft_free_all(ENV_LIST);
  ft_free_all(SOME_LIST);
}
