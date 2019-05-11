#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>

int     voir_touche()
{
  char     buff[50] = {0};

  while (1)
  {
    read(0, buff, 4);
    printf("%d: [1]:%d\t[2]:%d\n", buff[0], buff[1], buff[2]);
  }
  return (0);
}

int              main(int ac, char **av, char **env)
{
  char           *name_term;
  struct termios term;

  if ((name_term = getenv("TERM")) == NULL)
     return (-1);
  if (tgetent(NULL, name_term) == 0)
     return (-1);
  // remplis la structure termios des possibilités du terminal.
  if (tcgetattr(0, &term) == -1)
     return (-1);
  voir_touche();
return (0);
}
