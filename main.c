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
	char *buffer = NULL;
	size_t line_cap = BUFSIZ;
	FILE *file = NULL;
	bool end_of_file = false;
	stack_tt *stack = NULL;
	/*sort the stack variable out*/
	stack = malloc(sizeof(stack_tt));
	stack->prev = NULL;
	stack->n = 10;
	stack->next = NULL;

	/*del from here up to prev comment*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		/*fix err msg*/
		fclose(file);
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

	} while (!end_of_file);
	current_line--;
	printf("so far so good, %d, %s\n", current_line, argv[1]);

	fclose(file);
	return (0);
}
