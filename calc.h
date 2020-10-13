#ifndef _CALC_H_
#define _CALC_H_

#define NUMBER '0'

void operand_stack_push(double f);
double operand_stack_pop(void);
int operand_stack_isempty(void);
double operand_stack_peek(void);

void operator_stack_push(char op);
char operator_stack_pop(void);
int operator_stack_isempty(void);
char operator_stack_peek(void);

void process(void);

int getop(char s[]);

#endif
