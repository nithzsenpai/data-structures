#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*next;
    struct node*prev;
    };
struct node*create(int value)
{
    struct node*new =(struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

struct node* insertfront(struct node**head,int value)

{

    struct node*new=create(value);
     struct node*temp=*head;
    if(*head==NULL)
        *head=new;
    else
    {
        new->next=*head;
        temp->prev=new;
        *head=new;
    }
    return new;
}
struct node *insertleft(struct node **head,int valuesearch,int value)
{
    struct node*new=create(value);
    struct node*temp=*head;
    while(temp!=NULL)
    {

        if(temp->data==valuesearch && temp==*head)
        {
            temp->prev=new;
            new->next=temp;
            *head=new;
            break;

        }
        else if(temp->data==valuesearch && temp!=*head)
        {
            
            new->next=temp;
            new->prev=temp->prev;
            temp->prev->next=new;
            temp->prev=new;
            break;
        }
        else
        {
            temp=temp->next;
        }
   }
   return new;
}

struct node* deletevalue(struct node**head,int valuesearch)
{
    struct node*temp=*head;
    while(temp!=NULL)
    {
        if(temp->data==valuesearch && temp==*head)
        {
            *head=NULL;
            
            free(temp);
        }
        else if(temp->data==valuesearch && temp!=*head)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);


        }
        else if(temp->data==valuesearch&&temp->next==NULL)
        {
            temp->prev->next=NULL;
            free(temp);
        }
        else
        {
            temp=temp->next;
        }

    }
return *head;
}
void print1(struct node**head)
{
    struct node*temp=*head;
    while(temp!=NULL)
    {

        printf("->%d",temp->data);
        temp=temp->next;
    }


}

int main()
{
    struct node*head=NULL;
    struct node*prev=NULL;
    int option=0,valuesearch1,value1,valuesearch2,value2;


   


         printf("menu:\n1)insert left of specific node\n2)delete a specific value\n3)insert a node\n4)display\n");

        int choice;
        
      

      do{
          printf("enter a choice:\n");
          scanf("%d",&choice);
          
            switch(choice)
           {

            case 1:
            {
                printf("enter a value:\n");
                scanf("%d",&value1);
                printf("enter value next to which to be inserted:\n");
                scanf("%d",&valuesearch1);
                insertleft(&head,valuesearch1,value1);
                break;
            }
            case 2:
            {
                printf("enter a value to be deleted:\n");
                scanf("%d",&valuesearch2);
                deletevalue(&head,valuesearch2);
                printf("value deleted!!\n");\
                break;

            }
            case 3:
            {
                printf("enter a value:\n");
                scanf("%d",&value2);
                insertfront(&head,value2);
                break;
            }
            case 4:
            {
                printf("elements present are:\n");
                print1(&head);
                break;
            }

       }


      }while(choice!=6);
    
   
}
