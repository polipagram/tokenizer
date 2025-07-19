#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
#include <unistd.h>
 #include <readline/readline.h>
 #include <readline/history.h>
# include <stdio.h>

# define ENV_LIST 1
# define SOME_LIST 2


typedef enum e_token
{
    PIPE = 1,
    RED_IN,
    RED_OUT,
    HEREDOC,
    DELEMITER,
    FILENAME,
    RED_APPEND,
    WORD,
    INVALID
}t_token;

typedef struct s_shell
{
    char    *value;
    t_token kind;
    struct s_shell *next;
    struct s_shell *previous;
}t_shell;

typedef struct s_list{
  void *content;
  struct s_list *next;
  struct s_list *previous;
} t_list;

void *ft_malloc(size_t size, int flag);
t_list *ft_global(t_list *ptr, int flag);
t_list *ft_lstnew(void *ptr);
void *ft_lstadd_front(t_list **head, t_list *new);
void  ft_clean_up(void);
void ft_free_all(int flag);
void ft_free(void *ptr, int flag);
void	*ft_memset(void *ptr, int c, size_t nbrb);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void syntax_opp_error(char *str, int size);
void syntax_qot_error(char qot);
int tokenization(t_shell *head);
int    ft_isspace(char k);
void *add_token_back(t_shell **head, t_shell *new);
t_shell *lst_new_token(char *str);
void lst_clear_token(t_shell **head);
int    ft_strcmp(char *s1, char *s2);
int word(char *str, t_shell **head);

#endif
