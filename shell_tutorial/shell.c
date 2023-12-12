#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	write(1, "#cisfun$ ", 9);
	getline(&buf, &buf_size, stdin);
}
	return (0);
