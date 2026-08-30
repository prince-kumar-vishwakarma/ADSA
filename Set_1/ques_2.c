#include <stdio.h>
// #include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int values[MAX];
char operators[MAX];

int vtop = -1, otop = -1;

void pushValue(int value){
    values[++vtop] = value;
}

int popValue(){
    return values[vtop--];
}

void pushOperator(char op){
    operators[++otop] = op;
}

char popOperator(){
    return operators[otop--];
}

char peekOperator(){
    return operators[otop];
}

int precedence(char op){
    if (op == '/' || op == '*')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int applyOperator(){
    int a, b;
    char op = popOperator();

    b = popValue();
    a = popValue();

    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }

    return 0;
}

int evaluate(char *expr){
    int i = 0;

    while (expr[i] != '\0')
    {
        /* Ignore spaces */
        if (isspace(expr[i]))
        {
            i++;
            continue;
        }

        /* Operand */
        if (isdigit(expr[i]))
        {
            pushValue(expr[i] - '0');
        }

        /* Left parenthesis */
        else if (expr[i] == '(')
        {
            pushOperator(expr[i]);
        }

        /* Right parenthesis */
        else if (expr[i] == ')')
        {
            while (otop != -1 && peekOperator() != '(')
                pushValue(applyOperator());

            popOperator(); // Remove '('
        }

        /* Operator */
        else if (expr[i] == '+' || expr[i] == '-' ||
                 expr[i] == '*' || expr[i] == '/')
        {
            while (otop != -1 &&
                   peekOperator() != '(' &&
                   precedence(peekOperator()) >= precedence(expr[i]))
            {
                pushValue(applyOperator());
            }

            pushOperator(expr[i]);
        }

        i++;
    }

    /* Apply remaining operators */
    while (otop != -1)
        pushValue(applyOperator());

    return popValue();
}

int main(int argc, char *argv[])
{
    char expression[MAX] = "";

    if (argc < 2){
        printf("Usage: %s \"expression\"\n", argv[0]);
        return 1;
    }

    /* Join command-line arguments to preserve spaces */
    for (int i = 1; i < argc; i++){
        strcat(expression, argv[i]);
    }

    printf("Value = %d\n", evaluate(expression));

    return 0;
}
