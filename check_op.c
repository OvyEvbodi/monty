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
	/*tokenize str
	get opcode 
	update global variable with opcode
	check if it's push, if yes, call the push func
	if no, check other functions and call one
	else, print err msg

	*/
	char *opcode_str = strtok(*buffer, DELIM);
	int data = 0, i = 0;

	instruction_t ops[] = {
		{"pop", _pop},
		{"pall", _pall},
		{"pint", _pint},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"swap", _swap},
		{"nop", _nop},
		{NULL, NULL}
	};

	if (strcmp(opcode_str, "push") == 0)
	{
		data = atoi(strtok(NULL, DELIM));
		if (isdigit(data) != 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			/*fclose(file);
			free(*buffer);
			*buffer = NULL;
			fix if else condition err
			*/
			exit(EXIT_FAILURE);
		}
		else if (isdigit(data) == 0)
			_push(stack, data);
		/*printf("from push func, data var -> %d", data);*/
	}
	for (; ops[i].opcode; i++)
		if (!strcmp(opcode_str, ops[i].opcode))
			ops[i].f(stack, line_number);
	/*free buffer right before any exit point!! 
	this is just a reminder, nothing to free here..
	e.g: stack overflow and underflow
	*/
	return (0);
}
