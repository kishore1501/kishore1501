#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head,*temp,*new_node;
void create_list(int n);
void display_list();
int main()
{
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create_list(n);
    printf("\nData in the list\n");
    display_list();
    return 0;
}
void create_list(int n)
{
    int i,data;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
        printf("Unable to allocate memory");
    else
    {
        printf("enter the data of node 1: ");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            printf("Enter the data of the node %d: ",i);
            scanf("%d",&data);
            new_node=(struct node*)malloc(sizeof(struct node));
            if(new_node==NULL)
                printf("Unable To Allocate Memory");
            else
            {
                new_node->data=data;
                new_node->next=NULL;
                temp->next=new_node;
                temp=temp->next;
            }
        }
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY");
    }
}   
void display_list()
{
    if(head==NULL)
        printf("Unable to allocate memory");
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