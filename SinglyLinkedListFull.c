#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition();
void Display();
void DisplayReverse(struct node *ptr);
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



void InsertAtBegin()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to add the Begin: ");
    scanf("%d", &temp->data);
    
    temp->next = NULL;
    
    
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
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


    if (head == NULL)
    {
        head = temp;
    }
    else
    {/************************************************************************* */
        struct node *ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        
        ptr->next = temp;
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
    
    int pos;
    
    if (head == NULL)
    {
        head = temp;
        return;
    }
    
    
    else
    { /* ******Using 2 pointers****** */
        
        struct node *prev_ptr = head;
        struct node *ptr = head;
        
        printf("Enter position to add the data: ");
        scanf("%d", &pos);
    /**************************************************************************************/    
    if (pos == 1) /*Similar to Insert at the Begin */
    {
        temp->next = head;
        head = temp;
        printf("Node Added to position %d!\n\n", pos);
        return ;
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

        if (ptr->next == NULL || ptr == NULL)
        {
            printf("Invalid position! Position is out of bounds!\n\n");
            return;
        }
            /************************************************************************************/

        prev_ptr = ptr;
        ptr = ptr->next;
    }
    
    
    temp->next=ptr;
    prev_ptr->next=temp;

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
        struct node *ptr = head;
        head = head->next;
        free(ptr);
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
        struct node *ptr = head;
        head = NULL;
        free(ptr);
        printf("Node Deleted!\n\n");
    }
    /************************************************************************************/
    else
    {
        struct node *prev_ptr = NULL;
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
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
    int pos;
    printf("Enter position to delete the data: ");
    scanf("%d", &pos);
    

    if (pos <= 0)
    {
        printf("Invalid position! Enter a valid position!\n\n");
        return ;
    }
    
    if (pos == 1)/*Similar to Delete Begin*/
    {
        struct node *ptr = head;
        head = head->next;
        free(ptr);
        printf("Node Deleted!\n\n");
        return ;

    }

        struct node *prev_ptr = head;
        struct node *ptr = head;
        
        for (int i = 0; i < pos-1; i++)
        {
            /************************************************************************************/
            if (ptr->next == NULL)
            {
                printf("Position is Out of Bound!\n\n");
                return ;
            }
            /************************************************************************************/
            prev_ptr = ptr;
            ptr = ptr->next;
        }

        prev_ptr->next = ptr->next;
        ptr->next = NULL;
        free(ptr);
        printf("Node Deleted!\n\n");
    }


    void Display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf(" \n\n");
}



void DisplayReverse(struct node *ptr)
{
    if (ptr == NULL) return; // හිස් කෝච්චියක් ආවොත් ආපසු හැරෙන්න 🛑
    if (ptr->next != NULL)
    {
        DisplayReverse(ptr->next);
    }
    printf("%d ", ptr->data);
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
    scanf("%d", &data);// &ptr->data

    ptr->data = data;

    printf("Node Updated!\n\n");
}

void freeList(struct node *ptr)
{
    if (ptr == NULL) return; // හිස් කෝච්චියක් නම් මකන්න දෙයක් නෑ 🛑
    if (ptr->next != NULL)
    {
        freeList(ptr->next);
    }
    free(ptr);
}