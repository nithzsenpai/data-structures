#include <stdio.h>
#include<string.h>
int prece(char ch){
    if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch  == '-')
        return 1;
    else
        return -1;
}


void infixToPostfix(char e[]) {
  

    int max = 5;
    char stack[100];
    int top = -1;

    for (int i = 0; i < max; i++) {
        char ch = e[i];

        if ((ch >= 'a' && ch <= 'z') || (ch>= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            printf("%c",ch);
        }
     
        else if (ch == '(') {
            top++;
            stack[top] = ch;
            
        }
    
        else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
           printf("%c",stack[top]);}
            top--; 
        }
   
        else {
            while (prece(e[i]) <= prece(stack[top]) )
                {printf("%c",stack[top]);
                top--;
                    
                }
                stack[top]=ch;}
        }
    }

   
int main() {
    char exp[10];
    printf("enter expression");
    scanf("%c",&exp);

   
    infixToPostfix(exp);

    return 0;
}
