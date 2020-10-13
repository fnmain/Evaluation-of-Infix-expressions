#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

#define MAXOP 80

//  return the rank of the operator
//  @return -1 if the char ch is not an operator; or
//  the rank listed as 1 for * and /, 2 for + and -
static int oprank(char ch);

int main(int argc, char const *argv[])
{
    int type = 0;
    char s[MAXOP];
    while ((type = getop(s)) != '\n') {
        if (type == NUMBER) {
            operand_stack_push(atof(s));
        } else if (type == '(') {
            operator_stack_push('(');
        } else if (type == ')') {
            while (operator_stack_peek() != '(') {
                process();
            }
            operator_stack_pop();
        } else if (type == '+'
                || type == '-'
                || type == '*'
                || type == '/'){
            if (operator_stack_isempty()) {
                operator_stack_push(type);
            } else if (oprank(type) < oprank(operator_stack_peek())) {
                operator_stack_push(type);
            } else {
                process();
                operator_stack_push(type);
            }
        }
    }
    while (!operator_stack_isempty()) {
        process();
    }
    printf("Result: %g\n", operand_stack_pop());
    return 0;
}

static int oprank(char ch)
{
    int ret = -1;
    if (ch == '+' || ch == '-')
    {
        ret = 2;
    }
    else if (ch == '*' || ch == '/')
    {
        ret = 1;
    }
    return ret;
}
