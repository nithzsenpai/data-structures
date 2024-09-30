#include <stdio.h>
int push();
int pop();
int display();
int max=4,top=-1;
int main()
{
int n,i,j,choice;
printf("enter max size of array:");
scanf("%d",&n);
int stack[n];
do
{printf("enter your choice:\n 1)push\n2)pop\n3)display\n 4)exit");
scanf("%d",&choice);
switch(choice)
{case 1:
{push();
break;}
case 2:
{pop();
break;}
case 3:
{display();
break;}
case 4:
{
    printf("this is exit botton:");
    
}
 default:
{
     printf("enter valid choice");
     
}
}
while(choice!=4);
return 0; } }

int push(){
    if(top>=max)
    printf("stack is full");
    else{
        top++;
        int val;
        printf("enter your element:");
        scanf("%d",&val);
        stack[top]=val;
        
    }
}

int pop()
{
    if(top==-1)
    printf("stack is empty");
    else
    {
        int dat;
        dat=stack[top];
        top--;
        printf("top is popped");
        
    }
}

int display()
{int i;
if(top>max-1)
printf("overflow");
else
for(i=top;i<=0;i--)
printf("element is %d",&stack[i]);
}

