#include "calc.h"

//  (i) pop operand stack once (value1) 
//  (ii) pop operator stack once (operator) 
//  (iii) pop operand stack again (value2) 
//  (iv) compute value2 operator  value1
//  (v) push the value obtained in operand stack.
void process(void)
{
    double op2 = operand_stack_pop();
    char op = operator_stack_pop();
    double op1 = operand_stack_pop();
    double value;

    switch (op)
    {
    case '+':
        value = op1 + op2;
        break;
    case '-':
        value = op1 - op2;
        break;
    case '*':
        value = op1 * op2;
        break;
    case '/':
        value = op1 / op2;
        break;
    default:
        break;
    }

    operand_stack_push(value);
}