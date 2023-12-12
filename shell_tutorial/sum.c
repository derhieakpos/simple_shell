#include <stdio.h>
#include <unistd.h>

/**
 * main - ac and av
 * @ac: number of arguments count
 * @av: number of contents in an array
 * Return: Always 0.
*/
int main(int argc, char **argv)
{
	(void)argc;
	int i = 0; 

	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
