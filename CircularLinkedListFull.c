#include <stdio.h>
#include <stdlib.h>

struct node {
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
void DisplayReverseHelper(struct node *ptr);
void DisplayReverse();
void Search();
void Update();
void freeList();

int main() {
    int choice;
    do {
        printf("\n1.Insert at begin\n2.Insert at end\n3.Insert at position\n4.Delete at begin\n5.Delete at end\n6.Delete at position\n7.Display linked List\n8.Display Linked List(Reversed)\n9.Search data\n10.Update\n11.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: InsertAtBegin(); break;
            case 2: InsertAtEnd(); break;
            case 3: InsertAtPosition(); break;
            case 4: DeleteAtBegin(); break;
            case 5: DeleteAtEnd(); break;
            case 6: DeleteAtPosition(); break;
            case 7: Display(); break;
            case 8: DisplayReverse(); break;
            case 9: Search(); break;
            case 10: Update(); break;
            case 11: 
                freeList();
                printf("කෝච්චිය ගලවා ඉවත් කළා. ආයුබෝවන්! 👋\n");
                exit(0);
            default:
                printf("Invalid Operation\n\n");
        }
    } while(choice != 11);
    return 0;
}

void InsertAtBegin() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to add the Begin: ");
    scanf("%d", &temp->data);
    
    if (head == NULL) {
        head = temp;
        temp->next = head; // රවුමට සම්බන්ධ කිරීම 🔄
    } else {
        struct node *ptr = head;
        while(ptr->next != head) { // අන්තිම පෙට්ටිය හොයනවා
            ptr = ptr->next;
        }
        temp->next = head;
        ptr->next = temp;
        head = temp; // අලුත් එන්ජිම
    }
    printf("Node Added the Begin!\n\n");
}

void InsertAtEnd() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to add the End: ");
    scanf("%d", &temp->data);

    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        struct node *ptr = head;
        while(ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head; // අන්තිම පෙට්ටිය ආයෙත් එන්ජිමට 🔗
    }
    printf("Node Added the End!\n\n");
}

void InsertAtPosition() {
    int pos;
    printf("Enter position to add the data: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position!\n\n");
        return;
    }
    if (pos == 1) {
        InsertAtBegin();
        return;
    }

    if (head == NULL) {
        printf("List is empty. Use Insert at Begin first.\n\n");
        return;
    }

    struct node *ptr = head;
    struct node *prev_ptr = NULL;
    
    for (int i = 1; i < pos; i++) {
        prev_ptr = ptr;
        ptr = ptr->next;
        // රවුම ඉවරවෙලත් තැනක් හම්බවුනේ නැත්නම් 🛑
        if (ptr == head && i < pos - 1) {
            printf("Invalid position! Out of bounds!\n\n");
            return;
        }
    }

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to add: ");
    scanf("%d", &temp->data);
    
    temp->next = ptr;
    prev_ptr->next = temp;
    printf("Node Added to position %d!\n\n", pos);
}

void DeleteAtBegin() {
    if (head == NULL) {
        printf("Linked List is empty! Nothing to delete!\n");
        return;
    }
    struct node *temp = head;
    
    if (head->next == head) { // එක පෙට්ටියයි නම් 📦
        head = NULL;
        free(temp);
    } else {
        struct node *ptr = head;
        while(ptr->next != head) {
            ptr = ptr->next;
        }
        head = head->next;
        ptr->next = head; // අන්තිම පෙට්ටිය අලුත් එන්ජිමට සම්බන්ධ කිරීම
        free(temp);
    }
    printf("Node Deleted!\n\n");
}

void DeleteAtEnd() {
    if (head == NULL) {
        printf("Linked List is empty! Nothing to delete!\n");
        return;
    }
    if (head->next == head) { // එක පෙට්ටියයි නම් 📦
        free(head);
        head = NULL;
        printf("Node Deleted!\n\n");
        return;
    }
    
    struct node *ptr = head;
    struct node *prev_ptr = NULL;
    while (ptr->next != head) {
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    prev_ptr->next = head; // ඊට කලින් එක එන්ජිමට සම්බන්ධ කරනවා
    free(ptr);
    printf("Node Deleted!\n\n");
}

void DeleteAtPosition() {
    if (head == NULL) {
        printf("Linked List is empty! Nothing to delete!\n");
        return;
    }
    int pos;
    printf("Enter position to delete the data: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position!\n\n");
        return;
    }
    if (pos == 1) {
        DeleteAtBegin();
        return;
    }

    struct node *ptr = head;
    struct node *prev_ptr = NULL;
    
    for (int i = 1; i < pos; i++) {
        prev_ptr = ptr;
        ptr = ptr->next;
        if (ptr == head) {
            printf("Position is Out of Bound!\n\n");
            return;
        }
    }
    
    prev_ptr->next = ptr->next;
    free(ptr);
    printf("Node Deleted!\n\n");
}

void Display() {
    if(head == NULL) {
        printf("\nList is empty!\n\n");
        return;
    }
    struct node *temp = head;
    printf("Circular List: ");
    do { // රවුමක් නිසා do-while පාවිච්චි කළා 🔄
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); 
    printf("(head)\n\n");
}

void DisplayReverseHelper(struct node *ptr) {
    if (ptr->next != head) {
        DisplayReverseHelper(ptr->next);
    }
    printf("%d -> ", ptr->data);
}

void DisplayReverse() {
    if (head == NULL) {
        printf("\nList is empty!\n\n");
        return;
    }
    printf("Reversed List: ");
    DisplayReverseHelper(head);
    printf("(head)\n\n");
}

void Search() {
    if (head == NULL) {
        printf("List is empty!\n\n");
        return;
    }
    int data;
    printf("Enter data to search: ");
    scanf("%d", &data);

    struct node *ptr = head;
    do {
        if (ptr->data == data) {
            printf("\nData in the list\n\n");
            return;
        }
        ptr = ptr->next;
    } while(ptr != head);
    
    printf("Data not in the list\n\n");
}

void Update() {
    if (head == NULL) {
        printf("Linked List is empty! Nothing to update!\n");
        return;
    }
    int pos;
    printf("Enter position to update the data: ");
    scanf("%d", &pos);
    
    if (pos <= 0) {
        printf("Invalid position!\n\n");
        return;
    }

    struct node *ptr = head;
    for (int i = 1; i < pos; i++) {
        ptr = ptr->next;
        if (ptr == head) {
            printf("Position is Out of Bound!\n\n");
            return;
        }
    }

    int data;
    printf("Enter new data: ");   
    scanf("%d", &data);
    ptr->data = data;
    printf("Node Updated!\n\n");
}

void freeList() {
    if (head == NULL) return;
    struct node *ptr = head;
    struct node *next_node;
    do {
        next_node = ptr->next;
        free(ptr);
        ptr = next_node;
    } while (ptr != head); // අන්තිම පෙට්ටිය වෙනකම් මකනවා 🗑️
    head = NULL;
}

