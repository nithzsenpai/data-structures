#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*next;};

struct node*create(int value)
{
    struct node*new =(struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->next=NULL;
    
    return new;
}
void insertfront(struct node**head,int value)

{

    struct node*new=create(value);
     struct node*temp=*head;
    if(*head==NULL)
       { *head=new;
        new->next=*head;}
    else
    {
       while(temp->next!=*head)
       {
        temp=temp->next;

       }
       temp->next=new;
       new->next=*head;
       *head=new;
       
       


        
    }
   
}
void display(struct node **head)
{
    struct node *temp=*head;
    printf("%d\n",temp->data);
    temp=temp->next;
    while(temp!=*head)
     {printf("%d\n",temp->data);
     temp=temp->next;}
    
}

void insertend(struct node**head,int data1)
{
    
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data1;
    new->next=NULL;
    struct node *temp=*head;
    
    if(*head==NULL)
    {
       insertfront(head,data1);
    }
    else
    { while(temp->next!=*head)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->next=*head;
    
    }
}
void insertposition(struct node **head,int data1,int position)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data1;
    
    
    if(position==0)
     insertfront(head,data1);
    else 
    {struct node *temp=*head;
    for(int i=0;temp!=NULL && i<position-1;i++)
    {
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    printf("executed\n");
    }
}
void deletefront(struct node **head)
{
    if(*head==NULL)
     {
         printf("list empty\n");
         
     }
     
     else if((*head)->next==*head)
     {
         struct node*link=*head;
         *head=NULL;
         free(link);
         
     }
     else{
    struct node *temp=*head;
    struct node *current=*head;
    
    
    while(current->next!=*head)
    {
        current=current->next;
    }
    current->next=temp->next;
    *head=temp->next;
    free(temp);

    
     }
}     
void deleteend(struct node **head)
{
     if(*head==NULL)
     {
         printf("list empty\n");
         
     }
     else {
     struct node *temp=*head;
     struct node*current=*head;
     while(current->next->next!=*head){
        current=current->next;
     
     }
    temp=current->next;
    current->next=*head;
    free(temp);
    
}
}
void deleteposition(struct node **head,int position)
{
     if(*head==NULL)
     {
         printf("list empty\n");
         
     }
     else if(position==0)
     { deletefront(head);
     }
     else{
         struct node *temp=*head;
         for(int i=0;temp!=NULL && i<position-1;i++)
         {
             temp=temp->next;
         }
         struct node*next=temp->next->next;
        free(temp->next);
        temp->next=next;
     }
    

}
int main()
{
    struct node *head=NULL;
    int option=0, n,p;
    
   
        int choice;
        printf("menu:\n1)insert at front\n2)insert at end\n3)insert at position\n4)delete at front\n5)delete at end\n6)delete at position\n7)display\n8)exit\n");
        do{
    
        
       printf("enter choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1: 
            {
                
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                insertfront(&head,n);
                break;
            }
            case 2:
            {
                
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                insertend(&head,n);
                break;
                
            }
            case 3:
            {
                
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                printf("enter position to be inserted\n");
                scanf("%d",&p);
                insertposition(&head,n,p);
                break;
            }
            case 4:
            {
                deletefront(&head);
                printf("element deleted\n");
                break;
            }
            case 5:
            {
                
                deleteend(&head);
                printf("element deleted\n");
                break;
            }
            case 6:
            {
                int p;
                printf("position to be deleted from\n");
                scanf("%d",&p);
                deleteposition(&head,p);
                printf("element deleted\n");
                break;
            }
            case 7:
            {
                printf("elements present are:\n");
                display(&head);
                break;
                
            }
            case 8:
            {
                printf("exit point\n");
            }
            
            
        }
        }
        while(choice!=8);
    
    return 0;
}




    
   
    



    
   
    

