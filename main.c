#include "monty.h"

glob_struct glob_var = {NULL, NULL, STACK};

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
	size_t line_cap = BUFSIZ;
	bool end_of_file = false;
	stack_tt *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	MYFILE = fopen(argv[1], "r");
	if (!MYFILE)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do {
		if (getline(&BUFFER, &line_cap, MYFILE) == -1)
			end_of_file = true;
		else
		{
			check_op(&stack, &BUFFER, current_line);
			current_line++;
		}
	free(BUFFER);
	BUFFER = NULL;
	} while (!end_of_file);
	free_stack(&stack);
	fclose(MYFILE);
	return (0);
}
