#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
     int data;
     struct node *next;
}NODE;

void create(NODE *head)
{
  NODE *newnode,*temp;
  int n,i;
  temp=head;
  printf("how many nodes:\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  newnode=(NODE *)malloc(sizeof(NODE));
  printf("Enter the data:\n");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  temp->next=newnode;
  temp=temp->next;
  } 
}
void display(NODE *head)
{
    NODE *temp;
    temp = head->next;
    while(temp!=NULL)
    {   
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}  

void append(NODE *head)
{
    NODE *newnode,*temp;
    newnode=(NODE *)malloc(sizeof(NODE));
    printf("\nEnter the data of node to be inserted:\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}


void insert(NODE *head)
{
    NODE *temp,*newnode;
    temp=head;
    int i=1,pos;
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->next=NULL;
    printf("\nEnter the data of the node to be inserted:\n");
    scanf("%d",&newnode->data);
    printf("Enter the position:\n");
    scanf("%d",&pos);
    while(i<=pos-1)
    { i++;
      temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void search(NODE *head)
{
    NODE *temp;
    temp=head;
    int key;
    printf("Enter the key:\n");
    scanf("%d",&key);
    while(key!=temp->data)
    {
        temp=temp->next;
        if(temp->next==NULL)
        {
            printf("kEY NOT FOUND.\n");
            return;
        }    
    } 
    printf("KEY FOUND."); 
}

void del_key(NODE *head)
{   
    int key;
    NODE *temp,*prev;
    temp=head;
    printf("Enter the key element to be deleted:\n");
    scanf("%d",&key);
    while(key !=temp->data)
    {
         prev=temp;
        temp=temp->next;
        if(temp->next==NULL)
        {
            printf("key not found.");
            return;
        }
    }
    prev->next=temp->next;
    temp->next=NULL;
 }

void del_pos(NODE *head)
{   int i=1,pos;
    NODE *temp,*prev;
    temp=head->next;
    printf("Enter the the position:\n");
    scanf("%d",&pos);
      while(i<=pos-1)
      {
        i++;
        prev=temp;
        temp=temp->next;
        if(temp==NULL)
        {
            printf("position out of bound.");
            return;
        }
        
      } 
      prev->next=temp->next;
        temp->next=NULL;
}

void main()
{ int ch;
  NODE *head;
  head=(NODE*)malloc(sizeof(NODE));
  head->next=NULL;
  create(head);
  printf("The created link list is :\n");
  display(head);
 
    while(1)
  {   printf("\nFollowing are the options to be performed on the above created link list:\n");
      printf("1:append \n2:insert \n3:search \n4:display \n5:delete by key \n6:delete by position \n7:exit");
 
      printf("\nEnter a choice:\n"); 
      scanf("%d",&ch);  
     switch(ch)
     {
        case 1:append(head);
               printf("\nlinklist after insretion of an elemet is:\n");
               display(head);
              break;
        case 2:insert(head);
               printf("\nlinklist after insretion of an elemet is:\n");
               display(head);
              break;
        case 3:search(head);
              break;
        case 4:display(head);
              break;
        case 5:del_key(head);
               printf("\nlinklist after deletion of an elemet is:\n");
               display(head); 
              break;
        case 6:del_pos(head);
               printf("\nlinklist after deletion of an elemet is:\n");
               display(head); 
              break;   
        case 7:exit(0);
               return; 
        default: printf("Invalid choice.\n");                                          
     } 
  }
}