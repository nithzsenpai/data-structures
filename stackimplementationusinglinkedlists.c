#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;};

void push(struct node **top,int data1)
{ struct node *new=(struct node*)malloc(sizeof(struct node));
  new->data=data1;
  new->next=(*top);
  (*top)=new;
  printf("value inserted\n");
}

int delete(struct node **top)
{
    int x;
    if(*top==NULL)
     {
         printf("list empty\n");
         return 0;
     }
    struct node *temp=*top;
    *top=temp->next;
    x=temp->data;
    free(temp);
    return x;
    
}     

void display(struct node **top)
{
    struct node *temp=*top;
    while(temp!=NULL)
     {printf("%d\n",temp->data);
     temp=temp->next;}
    
}

int main()
{
    struct node *head=NULL;
    int option=0, n,p;
    
    while(option!=1)
    {
        int choice;
        printf("menu:\n1)insert\n 2)delete\n 3)display\n 4)exit\n");
        do{
    
        
       printf("enter choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: 
            {
                
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                push(&head,n);
                break;
            }
            case 2:
            {
                int x=delete(&head);
                printf("element deleted is %d\n",x);
                break;
            }
            case 3:
            {
                printf("elements present are:\n");
                display(&head);
                break;
            }
            case 4:
            {
                printf("exit point\n");
                break;
            }

            }
               
                
            }
            while(choice!=4);

}
return 0;
}



