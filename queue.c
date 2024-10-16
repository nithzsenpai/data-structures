#include<stdio.h>
void insert(int *a[],int *front,int *rear,int max,int a1)

{

    if(*rear>=max)
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

int delete1(int *a[],int *front,int *rear,int max)
{
    int val;
    if(*front=*rear==-1 || *front=*rear)
    {
        printf("stack is empty");
    }
    else
    {val=*a[*front];
    *front++;
    return val;
    }
}

void display(int *a[],int *front,int *rear,int max)

{int i;
    if(*front=*rear==-1 ||*front==*rear==max)
    {
        printf("stack is empty");
    }
    else
    for(i=*front;i<=*rear;i++)
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
        {insert(&q[max],&front,&rear,max,val);
        break;}

        case 2:
        {
            delete1(&q[max],&front,&rear,max);
            break;
        }
        case 3:
        {
            display(&q[max],&front,&rear,max);
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



