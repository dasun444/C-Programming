#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void Display();
void DisplayReverse(struct node *ptr);
void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition();
void Search();
void Update();
void freeList(struct node *ptr);

struct node *head = NULL;

int main()
{
    int choice;

   do
    {
        printf("\n1.Insert at begin\n2.Insert at end\n3.Insert at position\n4.Delete at begin\n5.Delete at end\n6.Delete at position\n7.Display linked List\n8.Display Linked List(Reversed)\n9.Search data\n10.Update\n11.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertAtBegin();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtPosition();
            break;
        case 4:
            DeleteAtBegin();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteAtPosition();
            break;
        case 7:
            Display();
            break;
        case 8:
            DisplayReverse(head);
            break;
        case 9:
            Search();
            break;
        case 10:
            Update();
            break; 
        case 11:
            freeList(head);
            exit(0);
            break;   
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }while(choice != 11);
}

void Display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("_\n\n");
}

void DisplayReverse(struct node *ptr)
{
    if (ptr->next != NULL)
    {
        DisplayReverse(ptr->next);
    }
    printf("%d ", ptr->data);
}

void InsertAtBegin()
{
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    printf("Node Added!\n\n");
}

void InsertAtEnd()
{
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);

    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if (head == NULL)
    {
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        
        temp->data = data;
        temp->next = NULL;
        ptr->next = temp;
    }
    printf("Node Added!\n\n");
}

void InsertAtPosition()
{
    int pos;
    printf("Enter position to add the data: ");
    scanf("%d", &pos);
    int data;

    struct node *prevptr = NULL;
    struct node *ptr = head;

    struct node *temp = (struct node*)malloc(sizeof(struct node));

    if (pos == 0)
    {
        printf("Enter data to add: ");
        scanf("%d", &data);
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    else
    { 
        for (int i = 0; i < pos; i++)
        {
            if (ptr == NULL)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            prevptr = ptr;
            ptr = ptr->next;
        }

        printf("Enter data to add: ");
        scanf("%d", &data);

        
        temp->data = data;
        temp->next = ptr;
        prevptr->next = temp;
    }
    printf("Node Added!\n\n");
}

void DeleteAtBegin()
{
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    printf("Node Deleted!\n\n");
}

void DeleteAtEnd()
{
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    else if (head->next == NULL)
    {
        struct node *ptr = head;
        head = NULL;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
    else
    {
        struct node *prevptr = NULL;
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = NULL;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
}

void DeleteAtPosition()
{
    int pos;
    printf("Enter position to delete the data: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    else if (pos == 0)
    {
        struct node *ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
    else{
        struct node *prevptr = NULL;
        struct node *ptr = head;
            
        for (int i = 0; i < pos; i++)
        {
            if (ptr == NULL)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = ptr->next;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
}

void Search()
{
    int data;
    printf("Enter data to search: ");
    scanf("%d", &data);

    struct node *ptr = head;

    while(ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("\nData in the list\n\n");
            return ;
        }
        ptr = ptr->next;
    }
    printf("Data not in the list\n\n");
}

void Update()
{
    int pos;
    printf("Enter position to update the data: ");
    scanf("%d", &pos);
    
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to update!\n");
        return ;
    }
    
    else{
        struct node *ptr = head;
            
        for (int i = 0; i < pos; i++)
        {
            if (ptr == NULL)
            {
                printf("Invalid position! Enter a valid position!\n\n");
                return ;
            }
            ptr = ptr->next;
        }

        int data;
        printf("Enter new data: ");
        scanf("%d", &data);

        ptr->data = data;

        printf("Node Updated!\n\n");
    }
}

void freeList(struct node *ptr)
{
    if (ptr->next != NULL)
    {
        freeList(ptr->next);
    }
    free(ptr);
}