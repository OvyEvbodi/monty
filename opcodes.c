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
		/*printf("data -> %d\n", (*stack)->n);*/
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
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		fclose(file);
		/*how to free buffer??*/
		exit(EXIT_FAILURE);
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
	stack_tt *temp = *stack;
	ssize_t result = 0;
	short i = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	for (; i < 2; i++)
	{
		result += temp->n;
		temp = temp->next;
	}
	temp = temp->prev;
	temp->n = result;
	_pop(stack, line_number);

}
