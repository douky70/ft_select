#include <stdio.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char *res;
	char *brut = "/dev/pts/2";
	int res2 = isatty(STDOUT_FILENO);
	res = ttyname(STDOUT_FILENO);
	
	int fd = open(brut, O_RDWR);
	dprintf(fd, "Num: %s", res);
	return 0;
}
