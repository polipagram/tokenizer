#include "ft_malloc.h"

t_list **ft_global(t_list **ptr, int flag)
{
  static t_list **env;
  static t_list **something;

  if (ptr && flag == ENV_LIST)
    env = ptr;
  else if (ptr && flag == SOME_LIST)
      something = ptr;
  if (flag / 2 == ENV_LIST)
    env = NULL;
  else if (flag / 2 == SOME_LIST)
    something = NULL;
  if (flag == ENV_LIST)
    return (env);
  else if (flag == SOME_LIST)
    return (something);
  return (NULL);
}

void *ft_malloc(size_t size, int flag)
{
  void *ptr;
  t_list *tmp;
  t_list  *head;

  ptr = malloc(size);
  if (!ptr)
    return (perror("minishell"), ft_clean_up(), NULL);
  tmp = NULL;
  if (!head)
  {
    head = ft_global(NULL, flag);
    if (!ft_lst_add_back(&head, ft_lstnew(ptr)))
      return (perror("minishell"), ft_clean_up(), NULL);
  }
  else 
  {
    head = ft_global(NULL, flag); 
    if (!ft_lst_add_back(&head, ft_lstnew(ptr)))
      return (perror("minishell"), ft_clean_up(), NULL);
  }
  ft_global(&head, flag);
  return (ptr);
}

// int main()
// {
//   char *str;
//   char *content = "kawta";
//   int i = 0;

//   str = ft_+(6, 2);
//   while(content[i])
//   {
//     str[i] = content[i];
//     i++;
//   }
//   str[i] = '\0';
//   i = 0;
//   ft_clean_up();
// }
