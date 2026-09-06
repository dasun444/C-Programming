/*
Create a separate file in the same project and rename it as InsertionOfLinkedList.c
(i)Insert the new node which carries the value as 5 at head of the linked list.
(ii)Insert the new node which carries the value as 6 at the end of the node linked list.
(iii)Insert the new node which carries the value as 7 at 2nd position of the node linked list.
*/



#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data;
    struct node* next;
};
struct node* head = NULL;



void insertatBegin()
{
struct node *temp =(struct node*)malloc(sizeof(struct node));//creating

printf("Enter node data: ");
scanf("%d",&temp->data);
temp->next = NULL;
if(head==NULL)
{
head=temp;
return;
}
else
{
temp->next = head;
head= temp;
}
}



void insertatEnd()
{
struct node *temp;
temp =(struct node*)malloc(sizeof(struct node));//creating a new node
printf("Enter node data: ");
scanf("%d",&temp->data);
temp->next = NULL;
if(head==NULL)
{
head=temp;
return;
}
else
{
struct node* ptr =head;
while(ptr->next!=NULL)
{
ptr= ptr->next;
}
ptr->next = temp;
}
}



void insertatPos(){
struct node *temp;
temp =(struct node*)malloc(sizeof(struct node));//creating a new node
printf("Enter the data: ");
scanf("%d",&temp->data);
temp->next = NULL;
if(head==NULL)
{
head=temp;
return;
}
else
{
struct node* prev_ptr = NULL;
struct node* ptr = head;
int pos;
printf("Enter the position: ");
scanf("%d",&pos);
for(int i=0;i < pos ;i++)
{
prev_ptr = ptr;
ptr =ptr ->next;
}
temp ->next =ptr;
prev_ptr->next = temp;
}
}


void insert(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Display() {
    struct node* temp = head;
    printf("\n head=>");
    while (temp != NULL) {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" [null]\n");
}

int main() {
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(0);

    Display();
    insertatBegin();
    Display();
    insertatEnd();
    Display();
    insertatPos();
    Display();
    return 0;
}