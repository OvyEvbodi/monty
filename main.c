#include "monty.h"

/**
 * main - Entry point to program
 * @argc: argument count
 * @argv: a pointer to the strings of arguments
 *
 * Return: 0 on success,
 * otherwise, 1
*/

FILE *file = NULL;
int main(int argc, char *argv[])
{
	int current_line = 1;
	char *buffer = NULL;
	size_t line_cap = BUFSIZ;
	
	bool end_of_file = false;
	stack_tt *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	do {
		if (getline(&buffer, &line_cap, file) == -1)
			end_of_file = true;
		else
		{
			/*check opcode*/
			check_op(&stack, &buffer, current_line);
			printf(" %d, %s\n", current_line, buffer);
			current_line++;
	
		}
	free(buffer);
	buffer = NULL;
	} while (!end_of_file);
	current_line--;

	fclose(file);
	return (0);
}
