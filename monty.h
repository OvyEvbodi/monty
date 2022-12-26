#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>

#define DELIM " \n\t"
#define BUFFER glob_var.buffer
#define MYFILE glob_var.file
#define MODE glob_var.mode
#define PRINTABLE_DATA temp && temp->n != 0 && temp->n > 32 && temp->n < 127
#define STACK 1
#define QUEUE 0

#define OPERATIONS                                                     \
instruction_t ops[] = {{"stack", _mode}, {"queue", _mode},             \
		{"pop", _pop}, {"pall", _pall}, {"pint", _pint},               \
		{"add", _add}, {"sub", _sub}, {"div", _div}, {"rotr", _rotr},  \
		{"mul", _mul}, {"swap", _swap}, {"mod", _mod}, {"rotl", _rotl},\
		{"nop", _nop}, {"pchar", _pchar}, {"pstr", _pstr}, {NULL, NULL}\
	}

#define EXITFUNC                                                      \
fclose(MYFILE);                                                       \
free(BUFFER);                                                         \
BUFFER = NULL;                                                        \
exit(EXIT_FAILURE)                                                    \

typedef struct glob_v
{
	char *buffer;
	FILE *file;
    unsigned short mode:1;
} glob_struct;

extern glob_struct glob_var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_tt; /*change name to stack_t*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_tt **stack, unsigned int line_number);
} instruction_t;

int check_op(stack_tt **stack, char **buffer, int line_number);

void _pop(stack_tt **stack, unsigned int line_number);
void _pall(stack_tt **stack, unsigned int line_number);
void _pint(stack_tt **stack, unsigned int line_number);
void _add(stack_tt **stack, unsigned int line_number);
void _nop(stack_tt **stack, unsigned int line_number);
void _swap(stack_tt **stack, unsigned int line_number);
void _sub(stack_tt **stack, unsigned int line_number);
void _div(stack_tt **stack, unsigned int line_number);
void _mul(stack_tt **stack, unsigned int line_number);
void _mod(stack_tt **stack, unsigned int line_number);
void _pchar(stack_tt **stack, unsigned int line_number);
void _pstr(stack_tt **stack, unsigned int line_number);
void _rotl(stack_tt **stack, unsigned int line_number);
void _rotr(stack_tt **stack, unsigned int line_number);
void _mode(stack_tt **stack, unsigned int line_number);

void _push(stack_tt **stack, int data);
void free_stack(stack_tt **stack);

#endif /*MONTY_H*/
