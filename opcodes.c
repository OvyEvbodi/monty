#include "monty.h"

/**
 * _pop - pops a node from the top of the stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _pop(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	else
	{
		printf("data -> %d\n", (*stack)->n);
		temp = *stack;
		if ((*stack)->next)
			(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}
	fclose(file);
}

/**
 * _push - pushes a new node on to the stack
 * @stack: a pointer to the top of the stack
 * @data: the data to be pushed on to the stack
*/
void _push(stack_tt **stack, int data)
{
	stack_tt *new = NULL;

	if (!*stack)
	{
		*stack = malloc(sizeof(stack_tt));
		(*stack)->prev = NULL;
		(*stack)->n = data;
		(*stack)->next = NULL;
	}
	else
	{
		new = malloc(sizeof(stack_tt));
		new->n = data;
		new->prev = NULL;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	fclose(file);
}
