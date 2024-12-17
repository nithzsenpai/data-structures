#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

// Function to check operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to perform infix to postfix conversion
void infixToPostfix(char* infix, char* postfix) {
    char stack[SIZE];
    int top = -1;
    int j = 0; // Index for postfix array

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            // Operand: Add to postfix
            postfix[j++] = ch;
        } else if (ch == '(') {
            // Left parenthesis: Push to stack
            stack[++top] = ch;
        } else if (ch == ')') {
            // Right parenthesis: Pop until '(' is found
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top == -1) {
                printf("Invalid expression: Mismatched parentheses.\n");
                return;
            }
            top--; // Pop the '(' from the stack
        } else if (isOperator(ch)) {
            // Operator: Pop higher or equal precedence operators
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch; // Push current operator to stack
        } else {
            printf("Invalid character '%c' in expression.\n", ch);
            return;
        }
    }

    // Pop remaining operators from the stack
    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid expression: Mismatched parentheses.\n");
            return;
        }
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


