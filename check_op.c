#include "monty.h"

/**
 * check_op - checks the opcode on a line from a file,
 * and calls the appropriate function
 *
 * @buffer: the buffer containing the opcode and its argument(s)
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: a call to the appropriate operation function
*/

int check_op(stack_tt **stack, char **buffer, int line_number)
{
	char *opcode_str = strtok(*buffer, DELIM), *char_data = NULL;
	int data = 0, i = 0;
	bool digits = true;

	instruction_t ops[] = {
		{"pop", _pop}, {"pall", _pall},
		{"pint", _pint}, {"add", _add},
		{"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"swap", _swap},
		{"mod", _mod}, {"nop", _nop},
		{NULL, NULL}
	};
	if (strcmp(opcode_str, "push") == 0)
	{
		char_data = (strtok(NULL, DELIM));
		for (i = 0; char_data[i]; i++)
			if (isdigit(char_data[i]) == 0)
			{
				digits = false;
				break;
			}
		if (!digits)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
			line_number);
			fclose(MYFILE);
			free(*buffer);
			*buffer = NULL;
			exit(EXIT_FAILURE);
		}
		data = atoi(char_data);
		_push(stack, data);
	}
	for (i = 0; ops[i].opcode; i++)
		if (!strcmp(opcode_str, ops[i].opcode))
			ops[i].f(stack, line_number);
	return (0);
}
