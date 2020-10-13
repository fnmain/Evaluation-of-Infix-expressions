#include <stdlib.h>
#include <stdio.h>

#include "calc.h"

struct node {
    double value;
    struct node *next;
};

static struct node *operand_stack_head = NULL;
static struct node *operator_stack_head = NULL;

struct node *node_alloc(void)
{
    return (struct node *)malloc(sizeof(struct node));
}

/* push函数：把f压入到 operand 堆栈中 */
void operand_stack_push(double f)
{
    struct node *p = node_alloc();
    p->value = f;
    p->next = operand_stack_head;
    operand_stack_head = p;
}

/* pop函数：弹出并返回 operand 栈顶的值 */
double operand_stack_pop(void)
{
    double ret = 0.0;
    struct node *t;
    if (operand_stack_head != NULL) {
        ret = operand_stack_head->value;
        t = operand_stack_head->next;
        free(operand_stack_head);
        operand_stack_head = t;
    } else {
        printf("error: stack empty\n");
    }
    return ret;
}

int operand_stack_isempty(void)
{
    return operand_stack_head == NULL;
}

double operand_stack_peek(void)
{
    double ret = operand_stack_pop();
    operand_stack_push(ret);
    return ret;
}

/* push函数：把op压入到 operator 堆栈中 */
void operator_stack_push(char op)
{
    struct node *p = node_alloc();
    p->value = op;
    p->next = operator_stack_head;
    operator_stack_head = p;
}

/* pop函数：弹出并返回 operator 栈顶的值 */
char operator_stack_pop(void)
{
    char ret = '\0';
    struct node *t;
    if (operator_stack_head != NULL) {
        ret = operator_stack_head->value;
        t = operator_stack_head->next;
        free(operator_stack_head);
        operator_stack_head = t;
    } else {
        printf("error: stack empty\n");
    }
    return ret;
}

int operator_stack_isempty(void)
{
    return operator_stack_head == NULL;
}

char operator_stack_peek(void)
{
    char ret = operator_stack_pop();
    operator_stack_push(ret);
    return ret;
}

// #define _TEST_
#ifdef _TEST_

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 5; i++) {
        push(i);
    }

    for (int i = 0; i < 4; i++) {
        printf("%f\n", pop());
    }
    for (int i = 0; i < 5; i++) {
        push(i);
    }

    for (int i = 0; i < 6; i++) {
        printf("%f\n", pop());
    }
    return 0;
}

#endif