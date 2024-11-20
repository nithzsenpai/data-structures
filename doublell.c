include<stdio.h>
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

void insertfront(struct node**head,struct node**prev,int value)

{

    struct node*new=create(value);
     struct node*temp=*head;
    if(*head==NULL)
        *head=new;
    else
    {
        new->next=*head;
        temp->next->prev=new;
    }
}
void insertleft(struct node **head,struct node**prev,int valuesearch,int value)
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

        }
        else if(temp->data==valuesearch && temp!=*head)
        {
            temp->prev=new;
            new->next=temp;
            new->prev=temp->prev;
        }
        else
        {
            temp=temp->next;
        }
   }
}

void deletevalue(struct node**head,struct node**prev,int valuesearch)
{
    struct node*temp=*head;
    while(temp!=NULL)
    {
        if(temp->data==valuesearch && temp==*head)
        {
            *head=temp->next;
            temp->next->prev=NULL;
            free(temp);
        }
        else if(temp->data==valuesearch && temp!=*head)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;


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
}
void print1(struct node**head)
{
    struct node*temp=*head;
    while(temp!=NULL)
    {

        printf("%d\n",temp->data);
        temp=temp->next;
    }


}

int main()
{
    struct node*head=NULL;
    struct node*prev=NULL;
    int option=0,valuesearch,value;

   
    printf("original list :\n");
    insertfront(&head,&prev,1);
    insertfront(&head,&prev,2);
    insertfront(&head,&prev,4);
    print1(&head);




         printf("menu:\n 1)insert left of specific node\n2)delete a specific value\n3)exit\n");

        int choice;
        while(option!=1)
      {


          printf("enter a choice:\n");
          scanf("%d",&choice);
          do{
            switch(choice)
           {

            case 1:
            {
                printf("enter a value:\n");
                scanf("%d",&value);
                printf("enter value next to which to be inserted:\n");
                scanf("%d",&valuesearch);
                insertleft(&head,&prev,valuesearch,value);

                break;
            }
            case 2:
            {
                printf("enter a value to be deleted:\n");
                scanf("%d",&valuesearch);
                deletevalue(&head,&prev,valuesearch);
                printf("value deleted!!\n");\
                break;

            }
            case 3:
            {
                printf("exit point\n");
                break;
            }

       }


      }while(choice!=6);
    }
    return 0;
}
