#include <stdio.h>
#include <ctype.h>

#define MAX 100


int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}


void push(char stack[], int *top, char value) {
    stack[++(*top)] = value;
}


char pop(char stack[], int *top) {
    return stack[(*top)--];
}

void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;
    char ch;

    
    while (infix[i] != '\0') {
        ch = infix[i];

        if (isalpha(ch)) {
            
            postfix[j++] = ch;
        } 
        else if (ch == '(') {
            
            push(stack, &top, ch);
        } 
        else if (ch == ')') {
            
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top);  
        } 
        else {
            
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, ch);
        }
        i++;
    }

    
    while (top != -1) {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0';  
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
