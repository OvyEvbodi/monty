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

	OPERATIONS;
	if (strcmp(opcode_str, "push") == 0)
	{
		char_data = (strtok(NULL, DELIM));
		for (i = 0; char_data && char_data[i]; i++)
			if (isdigit(char_data[i]) == 0)
			{
				digits = false;
				break;
			}
		if (!digits)
		{
			fprintf(stderr, "L%d: usage: push integer\n",
			line_number);
			free_stack(stack);
			EXITFUNC;
		}
		if (char_data)
		{
			data = atoi(char_data);
			_push(stack, data);
		}
	}
	else if (!opcode_str)
		return (0);
    else if (opcode_str[0] == '#')
		return (0);
    else
    {
        for (i = 0; ops[i].opcode; i++)
        {
            if (!strcmp(opcode_str, ops[i].opcode))
            {
                ops[i].f(stack, line_number);
                return (0);
            }
        }
        if (!ops[i].opcode)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n",
            line_number, opcode_str);
            free_stack(stack);
            EXITFUNC;
        }
    }
	return (0);
}
