#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _rotl(stack_tt **stack, unsigned int line_number)
{
    stack_tt *temp = NULL;
    stack_tt *prev_temp = NULL;
    (void)line_number;

    if (*stack)
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = *stack;
        temp->next->prev = temp;
        prev_temp = (*stack)->next;
        temp->next->next = NULL;
        *stack = prev_temp;
        (*stack)->prev = NULL;
    }
}

/**
 * _mode - sets the mode to stack/queue
 * @line_number: the current line number
 * @stack:a pointer to the top of the stack
 *
 * Return: void
*/

void _mode(stack_tt **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    if (strcmp(strtok(BUFFER, DELIM), "queue") == 0)
        MODE = QUEUE;
    else if (strcmp(strtok(BUFFER, DELIM), "stack") == 0)
        MODE = STACK;
}
