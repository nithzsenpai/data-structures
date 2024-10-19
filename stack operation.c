#include<stdio.h>


void push(int ele,int stack[],int *top,int n){
    if(*top == n-1){
        printf(" OVERFLOW \n");
    }
    else{
        (*top)++;
        stack[*top] = ele;
        printf("%d has been pushed \n",ele);
    }
}

void pop(int stack[],int *top){
    if((*top) == -1){
        printf(" UNDERFLOW \n");
    }
    else{
        int popped = stack[*top];
        (*top)--;
        printf("%d has been popped \n",popped);
    }
}

void display(int stack[],int *top){
    if((*top) == -1){
        printf("the stack is empty \n");
    }
    else{
        for(int i=0;i<=*top;i++){
            printf("%d \n",stack[i]);
        }
    }
}

int main()
{
    int option, val;
    while (1)
    {
        printf("\n\n1=Push\t2=Pop\t3=Display\t4=Exit");
        printf("\nSelect Option: ");
        scanf("%d", &opt);

        switch(opt)
        {
            case 1:
            {
                printf("Enter Push Element: ");
                scanf("%d", &val);
                push(val);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf(" Exit");
                return 0;
            }
            default:
                printf("Invalid Operations");
        }
    }
    return 0;
}
