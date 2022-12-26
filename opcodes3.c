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
 * free_stack - frees a stack list
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

/**
 * _pchar - prints the ASCII value of the top element of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _pchar(stack_tt **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
		line_number);
		free_stack(stack);
		EXITFUNC;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _pstr(stack_tt **stack, unsigned int line_number)
{
    stack_tt *temp = NULL;
    (void)line_number;

	if (!*stack)
	{
		free_stack(stack);
		EXITFUNC;
	}
    temp = *stack;
    while (PRINTABLE_DATA)
    {
        putchar(temp->n);
        temp = temp->next;
    }
    putchar('\n');  
}

/**
 * _rotr -  rotates the stack to the bottom
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _rotr(stack_tt **stack, unsigned int line_number)
{
    stack_tt *temp = NULL;
    int data = 0;
    (void)line_number;

    if (*stack)
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        data = temp->n;
        temp->n = (*stack)->n;
        (*stack)->n = data;
    }
}
