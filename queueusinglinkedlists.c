#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void enqueue(struct node**head,int data1)
{
    
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data1;
    new->next=NULL;
    struct node *temp=*head;
    
    if(*head==NULL)
    {
        (*head)=new;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    return;
    
}
void display(struct node **head)
{
    struct node *temp=*head;
    while(temp!=NULL)
     {printf("%d\n",temp->data);
     temp=temp->next;}
    
}


int dequeue(struct node **head)
{
    if(*head==NULL)
     {
         printf("list empty\n");
         return;
     }
    struct node *temp=*head;
    x=temp->data;
    *head=temp->next;
    free(temp);
    return x;
}  

int main()
{
    struct node *head=NULL;
    int option=0, n,p;
    
    while(option!=1)
    {
        int choice;
        //printf("menu:\n1)enqueue\n 2)dequeue\n 3)display\n 4)exit\n);
        do{
    
        
       printf("enter choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: 
            {
              

                
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                enqueue(&head,n);
                break;
                
            }
            case 2:
            {
                p=dequeue(&head);
                printf("element deleted is %d\n",p);
                break;
            }

            case 3:
            {
                printf("elements present are:\n");
                display(&head);
                break;
                
            }
            case 4;
            {
                printf("exit\n");
                break;
            }
        }
        }while(choice!=4);
    }
    return 0;
}
