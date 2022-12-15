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

	if (!(temp1->next) || !*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
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
	printf("testing pall\n");
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _add - adds the last 2 elements of a stack
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _sub(stack_tt **stack, unsigned int line_number)
{
	stack_tt *temp = (*stack)->next;
	ssize_t result = temp->n;

	if (!(*stack)->next || !*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	/*for (; i < 2; i++)
	{
		temp = temp->prev;
		result -= temp->n;
	}
	temp = temp->next;
	temp->n = result;*/
	/*updgrade*/
	result -= temp->prev->n;
	temp->n = result;
	_pop(stack, line_number);
}
