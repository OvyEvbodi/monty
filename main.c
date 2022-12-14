#include "monty.h"

/**
 * main - Entry point to program
 * @argc: argument count
 * @argv: a pointer to the strings of arguments
 *
 * Return: 0 on success,
 * otherwise, 1
*/

int main(int argc, char *argv[])
{
	int current_line = 1;

	if (argc != 2)
	{
		perror("Error: Can't open file ");
		/*fix err msg*/
		exit(EXIT_FAILURE);
	}
	printf("so far so good, %d, %s\n", current_line, argv[1]);


	return (0);
}
