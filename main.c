#include "ft_malloc.h"

void  print_list(t_shell *list)
{
  while (list)
  {
    printf("value = %s\n", list->value);
    switch (list->kind) {
      case PIPE:
      printf("PIPE\n");
      break;
      case 2:
      printf("infile\n");
      break;
     case 3:
      printf("outfile\n");
      break;
     case 4:
      printf("heredoc\n");
      break;
     case 5:
      printf("delemiter\n");
      break;
     case 6:
      printf("filename\n");
      break;
      case 7:
      printf("red_append\n");
      break;
       case 8:
      printf("word\n");
      break;
    }
    list = list->next;
  }
  printf("\n");
}

int main()
{
  char *input;
  t_shell *head;
  int ret;
  head = NULL;
  while(1)
  {
    input =  readline("minishell$> ");
    add_history(input);
    ret = word(input, &head);
    if (ret == -1)
      return (1);
    free(input);
    print_list(head);
  }
}
