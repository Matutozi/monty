#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#define MONTY_H
stack_t *stack = NULL;

#define MAX_STACK_SIZE 100
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
} stack_t;

typedef struct stack_s {
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct line_s {
	char *content;
	int number;
} line_t;

/* Global variables */
extern FILE *file;
extern char *operand;

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

line_t *textfile_to_array(const char *filename);
char **split_line(char *line);
void free_stack(stack_t *head);
void free_lines(line_t *lines);
void monty_error(monty_t *monty);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
int _atoi(char *s, int *n);
void get_swap(stack_t **stack, unsigned int line_number);
void get_sub(stack_t **stack, unsigned int line_number);
void get_rotr(stack_t **stack, unsigned int line_number);
void get_free(stack_t *stack);
void get_nop(stack_t **stack, unsigned int line_number);
#endif /*MONTY_H */
