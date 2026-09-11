#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;

void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition();
void Display();
void DisplayReverse();
void Search();
void Update();
void freeList(struct node *ptr);


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
            DisplayReverse();
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



void InsertAtBegin()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to add the Begin: ");
    scanf("%d", &temp->data);
    
    temp->next = NULL;
    temp->prev = NULL;/*************/
    
    
    if (head == NULL)
    {
        head = temp;
        tail = temp;/*************/
    }
    else
    {
        head->prev = temp;/*************/
        temp->next = head;
        head = temp;
    }
    printf("Node Added the Begin!\n\n");
}




void InsertAtEnd()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to add the End: ");
    scanf("%d", &temp->data);

    temp->next = NULL;
    temp->prev = NULL;/*************/
    
    
    if (head == NULL)
    {
        head = temp;
        tail = temp;/*************/
    }
    else
    {/************************************************************************* */
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    printf("Node Added the End!\n\n");
}
/************************************************************************* */


void InsertAtPosition()
{
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to add: ");
    scanf("%d", &temp->data);

        temp->next = NULL;
        temp->prev = NULL;/*************/
    
    int pos;
    
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    
    
    else
    { /* ******Using 2 pointers****** */
        
        struct node *ptr = head;
        struct node *prev_ptr = head;
        
        printf("Enter position to add the data: ");
        scanf("%d", &pos);
    /**************************************************************************************/    
    if (pos == 1) /*Similar to Insert at the Begin */
    {
        InsertAtBegin();
        return;
    }
    
    else if (pos <= 0 )
    {
        printf("Invalid position! Enter a valid position!\n\n");
        return ;
        
    }
    /**************************************************************************************/    
    
    
    for(int i=0; i<pos-1; i++)
    {
            /************************************************************************************/

        if (ptr->next == NULL)
        {
            printf("Invalid position! Position is out of bounds!\n\n");
            return;
        }
            /************************************************************************************/
        prev_ptr=ptr;
        ptr=ptr->next;
            
        }
        
        prev_ptr->next = temp;
        temp->prev = prev_ptr;/*************/
        temp->next = ptr;
        ptr->prev = temp;/*************/
    
    

    printf("Node Added to position %d!\n\n", pos);
    }
}


void DeleteAtBegin()
{
    
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    else
    {
        struct node *temp = head;/*************/
        head = temp->next;/*************/
        free(temp);
        printf("Node Deleted!\n\n");
    }
}





void DeleteAtEnd()
{
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    /************************************************************************************/
    /*Additonal*/
    else if (head->next == NULL)
    {
        struct node *temp = head;
        head = NULL;
        free(temp);
        printf("Node Deleted!\n\n");
    }
    /************************************************************************************/
    else
    {
        struct node *temp = tail;
        tail = temp->prev;/*************/
        tail->next = NULL;/*************/
        free(temp);
        
        printf("Node Deleted!\n\n");
    }
}


void DeleteAtPosition()
{
    if (head == NULL)
    {
        printf("Linked List is empty! Nothing to delete!\n");
        return ;
    }
    int pos;/*************/
    printf("Enter position to delete the data: ");
    scanf("%d", &pos);
    
    
    /************************************************************************************/
    if (pos <= 0)
    {
        printf("Invalid position! Enter a valid position!\n\n");
        return ;
    }
    
    if (pos == 1)/*Similar to Delete Begin*/
    {
        DeleteAtBegin();
        return ;

    }
    /************************************************************************************/

        struct node *ptr = head;
        
        for (int i = 0; i < pos-1; i++)
        {
            /************************************************************************************/
            if (ptr->next == NULL || ptr == NULL)
            {
                printf("Position is Out of Bound!\n\n");
                return ;
            }   
            /************************************************************************************/
        
            ptr=ptr->next;
        
        }
        if(ptr->prev != NULL) {
            ptr->prev->next = ptr->next;
        }

        if(ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }   
        else {
            tail = ptr->prev; // Update tail if deleting the last node
        }
        free(ptr);
        
        printf("Node Deleted!\n\n");
    }


    void Display()
{   
    printf("Doubly Linked List: ");                                              /*Similar code*/
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf(" \n\n");
}



void DisplayReverse()
{
  struct node *temp = tail;/*************/
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;/*************/
    }
    printf(" \n\n");  
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
        return;
    }

    if (pos <= 0)
    {
        printf("Invalid position! Enter a valid position!\n\n");
        return;
    }

    struct node *ptr = head;

    for (int i = 0; i < pos - 1; i++)
    {
        if (ptr == NULL || ptr->next == NULL)
        {
            printf("Position is Out of Bound!\n\n");
            return;
        }
        ptr = ptr->next;
    }

    int data;
    printf("Enter new data: ");
    scanf("%d", &data);//&ptr->data

    ptr->data = data;

    printf("Node Updated!\n\n");

    //??????
    if(ptr->next == NULL){
        tail=ptr;
    }
}

void freeList(struct node *ptr)
{
    if (ptr == NULL) return;
    if (ptr->next != NULL)
    {
        freeList(ptr->next);
    }
    free(ptr);
}