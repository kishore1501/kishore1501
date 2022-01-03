#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create_list(int n);
void display_list();
void insertnodeattheend(int data);
int main()
{
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create_list(n);
    printf("\nData in the list\n");
    display_list();
    printf("Enter the data to be inserted at the end: ");
    scanf("%d",&data);
    insertnodeattheend(data);
    printf("\nData in the list\n");
    display_list();
    return 0;
}
void create_list(int n)
{
    struct node *new_node,*temp;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        printf("Unable To allocate Memory");
    else
    {
        printf("Enter the date of node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        //from line 38-40 v have dealt with i=1
        for(i=2;i<=n;i++)
        {
            new_node=(struct node*)malloc(sizeof(struct node));
            if(new_node==NULL)
                printf("Unabe To Allocate Memory");
            else
            {
                printf("Enter the data of node %d: ",i);
                scanf("%d",&data);
                new_node->data=data;
                new_node->next=NULL;
                temp->next=new_node;
                temp=temp->next;
            } 
        }
        printf("Singly linked list created successfully");
    }
}
void insertnodeattheend(int data)
{
    struct node *new_node,*temp;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
        printf("Unable To Allocate Memory");
    else
    {
        new_node->data=data;
        new_node->next=NULL;
        temp=head;
        while(temp!=NULL && temp->next!=NULL)
            temp=temp->next;
        temp->next=new_node;
        printf("Data Successfully inserted");
    }
}
void display_list()
{
    struct node *temp;
    if(head==NULL)
        printf("Unable to allocate meomry");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("Data=%d\n",temp->data);
            temp=temp->next;
        }
    }
}