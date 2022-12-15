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
		free_stack(stack);
		EXITFUNC;
	}
	else
	{
		temp = *stack;
		if ((*stack)->next)
			(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}
}

/**
 * _push - pushes a new node on to the stack
 * @stack: a pointer to the top of the stack
 * @data: the data to be pushed on to the stack
 *
 * Return: void
*/
void _push(stack_tt **stack, int data)
{
	stack_tt *new = NULL;

	if (!*stack)
	{
		*stack = malloc(sizeof(stack_tt));
		if (!*stack)
			exit(EXIT_FAILURE);
		(*stack)->prev = NULL;
		(*stack)->n = data;
		(*stack)->next = NULL;
	}
	else
	{
		new = malloc(sizeof(stack_tt));
		if (!*stack)
			exit(EXIT_FAILURE);
		new->n = data;
		new->prev = NULL;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}


/**
 * _pint - prints the top element of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _pint(stack_tt **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
		line_number);
		free_stack(stack);
		EXITFUNC;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _add - adds the last 2 elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _add(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = NULL;
	ssize_t result = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
		line_number);
		free_stack(stack);
		EXITFUNC;
	}
	temp = *stack;
	result = temp->n + temp->next->n;
	temp->next->n = result;
	_pop(stack, line_number);
}

/**
 * _mul - multiplies the last 2 elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _mul(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = NULL;
	ssize_t result = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
		line_number);
		free_stack(stack);
		EXITFUNC;
	}
	temp = (*stack)->next;
	result = temp->n;
	result *= temp->prev->n;
	temp->n = result;
	_pop(stack, line_number);
}
