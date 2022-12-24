#include "monty.h"

/**
 * _mod - gets the remainder of the division
 * of the last 2 elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _mod(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = NULL;
	ssize_t result = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(stack);
		EXITFUNC;
	}
	temp = (*stack)->next;
	result = temp->n;
	if (temp->prev->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		EXITFUNC;
	}
	result %= temp->prev->n;
	temp->n = result;
	_pop(stack, line_number);
}

/**
 * free_stack_tt - frees a stack_tt list
 *
 * @stack: a pointer to the head node
 *
 * Return: void
*/

void free_stack(stack_tt **stack)
{
	stack_tt *temp = *stack;
	if (*stack)
	{
		while (temp->next)
		{
			temp = temp->next;
			free(temp->prev);
		}
		free(temp);
		temp = NULL;
	}
}
