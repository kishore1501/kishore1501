#include<stdio.h>
#include<stdlib.h>
struct node//  The elements present in the list(custom datatype)
{
    int data;// getting data from the user
    struct node* next;// pointer of the next node
}*head;
void create_list(int n);
void traverse_list();
int main()
{
    int n;//n=>number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create_list(n);//calling the func create_list
    printf("\nData in the List: \n");
    traverse_list();// calling the func traverse_list
    return 0;
}
void create_list(int n)
{
    struct node *newnode,*temp;
    head=(struct node*)malloc(sizeof(struct node));/*i am naming 
        1st node as head and allocatting space for the 1st node*/
    if(head==NULL)//checking if the list empty(n=0)
    {
        printf("unable to allocate memory");
        exit(0);
    }
    int data,i;
    printf("Enter the data of node 1: ");//getting the 1st node from me
    scanf("%d",&data);
    head->data=data;// link data field with data
    head->next=NULL;// link address with NULL
    //creating n-1 node and putting it inside an linked list
    temp=head;
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));/*allocatting
        space for n-1 nodes*/
        if(newnode==NULL)//chking for the last node
        {
            printf("unable to allocate memory");
            break;
        }
        printf("Enter the data of the node %d: ",i);
        scanf("%d",&data);
        newnode->data=data;//linking data to the newnode
        newnode->next=NULL;//making sure newnode points to NULL
        temp->next=newnode;//linking previous node with newnode
        temp=temp->next;//making current node as previous node
    }
}
void traverse_list()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list is empty");
        return ;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("data=%d\n",temp->data);//printing data of current node
        temp=temp->next;//updating temp to the next node
    }
}