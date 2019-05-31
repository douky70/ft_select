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
	  bzero(buff, sizeof(char) * 50);
    read(0, buff, 50);
    printf("[0]: %d, [1]: %d, [2]: %d, [3]: %d, [4]: %d, [5]: %d, [6]: %d, [7]: %d\n", buff[0], buff[1], buff[2], buff[3], buff[4], buff[5], buff[6], buff[7]);
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
	 term.c_lflag &= ~(ICANON); /* Met le terminal en mode non canonique. La fonction read recevra les entrées clavier en direct sans attendre qu'on appuie sur Enter */
    term.c_lflag &= ~(ECHO); /* Les touches tapées au clavier ne s'affficheront plus dans le terminal */
	tcsetattr(STDIN_FILENO, 0, &term);
  voir_touche();
return (0);
}
