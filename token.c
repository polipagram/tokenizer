#include "ft_malloc.h"

t_token redi_set(char *str)
{
    if (!ft_strcmp(str, ">>"))
        return (RED_APPEND);
    if (!ft_strcmp(str, "<<"))
        return (HEREDOC);
    if (!ft_strcmp(str, ">"))
        return (RED_OUT);
    if (!ft_strcmp(str, "<"))
        return (RED_IN);
    return (0);
}

int redi_error(char *str)
{
    ft_putstr_fd("minishell : syntax error unexpected token ", 2);
    ft_putstr_fd(str, 2);
    ft_putchar_fd('\n', 2);
    return(0);
}

int pipe_error(int flag, char *str)
{
    if (flag == 1)
        ft_putstr_fd("minishell : syntax error near unexpected token \'|\'\n", 2);
    else
    {
        ft_putstr_fd("minishell : syntax error unexpected opperator ", 2);
        ft_putstr_fd(str, 2);
        ft_putchar_fd('\n', 2);
    }
    return (-1);
}

int tokenization(t_shell *head)
{
  while (head)
  {
    if (*(head->value) == '|')
    {
      if (!(head->next) || !(head->previous))
        return (pipe_error(1, NULL));
      else if (*(head->value + 1) != '\0')
        return (pipe_error(2, head->value));
      else if (head->previous && head->previous->kind == PIPE)
        return (pipe_error(1, NULL));
      else
        head->kind = PIPE;
    }
    else if (*(head->value) == '>' || *(head->value) == '<')
    {
      if (!(head->next))
        return (redi_error("new line"));
      else
        head->kind = redi_set(head->value);
    }
    else
    head->kind = WORD;
    if (head->previous && (head->previous->kind != WORD && head->previous->kind != PIPE && head->previous->kind != FILENAME && head->previous->kind != DELEMITER))
    {
      if (head->kind != WORD)
        redi_error(head->value);
      else if (head->previous->kind == HEREDOC)
        head->kind = DELEMITER;
      else 
        head->kind = FILENAME;
    }
    head = head->next;
  }
  return(0);
}
