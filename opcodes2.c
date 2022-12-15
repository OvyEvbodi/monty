#include "monty.h"

/**
 * _nop -  does nothing
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _nop(stack_tt **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _swap - swaps the two topmost elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _swap(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp1 = NULL, *temp2 = NULL;

	if (!*stack || (!(*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		EXITFUNC;
	}
	temp1 = *stack;
	temp2 = (*stack)->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	temp2->prev = NULL;
	temp1->prev = temp2;
	*stack = temp2;

}

/**
 * _pall - prints all the elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _pall(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _sub - subracts the last 2 elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _sub(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = NULL;
	ssize_t result = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(stack);
		EXITFUNC;
	}
	temp = (*stack)->next;
	result = temp->n;
	result -= temp->prev->n;
	temp->n = result;
	_pop(stack, line_number);
}

/**
 * _div - divides the last 2 elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _div(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = NULL;
	ssize_t result = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	result /= temp->prev->n;
	temp->n = result;
	_pop(stack, line_number);
}
