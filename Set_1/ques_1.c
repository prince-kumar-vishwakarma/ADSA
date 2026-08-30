#include <stdio.h>
#include <ctype.h>
// #include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char op){
    switch (op)
    {
        case '/': return 4;
        case '*': return 3;
        case '+': return 2;
        case '-': return 1;
        default:  return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]){
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++){
        ch = infix[i];

        if (isdigit(ch)){
            postfix[j++] = ch;
        }
        else if (ch == '('){
            push(ch);
        }
        else if (ch == ')'){
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();

            if (top != -1 && peek() == '(')
                pop();  
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (top != -1 &&
                peek() != '(' &&
                precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main(){
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
