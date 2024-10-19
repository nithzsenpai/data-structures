#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert(int *a[MAX],int *front,int *rear,int a1)

{

    if(*rear>=MAX)
    printf("queue full");
    else if(*rear==-1 || *front==-1)
    {
        *front=*rear=0;
     *a[*rear]=a1;

    }
    else{
        *rear++;
         *a[*rear]=a1;
    }
}

int delete1(int *a[MAX],int *front,int rear)
{
    int val;
    if(*front=rear==-1 || *front==rear)
    {
        printf("stack is empty");
    }
    else
    {val=*a[*front];
    *front++;
    return val;
    }
}

void display(int *a[MAX],int front,int rear)

{int i;
    if(front=rear==-1 ||front==rear==MAX)
    {
        printf("stack is empty");
    }
    else
    for(i=front;i<=rear;i++)
    {
        printf("element is %d",*a[i]);
    }

}



int main()
{

int a,front=-1,rear=-1,max,val,choice;
printf("enter size");
scanf("%d",&max);
int q[max];

while(1)
{

    printf("enter choice:\n1)push \n 2)pop \n 3)display");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {insert(&q[MAX],&front,&rear,val);
        break;}

        case 2:
        {
            delete1(&q[MAX],&front,rear);
            break;
        }
        case 3:
        {
            display(q[MAX],front,rear);
            break;
        }
        case 4:
        printf("operations done");
        exit(0);

        default:
        printf("wrong choice");

        }

    }
    return 0;
    
    
}
