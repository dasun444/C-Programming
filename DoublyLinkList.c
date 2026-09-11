#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

void Display();
void DisplayReverse();
void InsertAtBegin(); 
void InsertAtEnd();
void InsertAtPosition();
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition();
void Search();
void Update();
void FreeList(struct node* ptr);

void Display() {
    struct node* temp = head;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nForward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void DisplayReverse() {
    struct node* temp = tail;
    if (tail == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nReverse: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void InsertAtBegin() {

    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &temp->data);

    temp->next = NULL;
    temp->prev = NULL;
    
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    printf("Inserted %d at beginning\n", temp->data);
}

void InsertAtEnd() {

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &temp->data);

    temp->next = NULL;
    temp->prev = NULL;
    
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    printf("Inserted %d at end\n", temp->data);
}

void InsertAtPosition() {
    int data, pos;
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position (1-based): ");
    scanf("%d", &pos);
    
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    
    if (pos == 1) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }
        printf("Inserted %d at position 1\n", data);
        return;
    }
    
    struct node* ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    newNode->next = ptr->next;
    newNode->prev = ptr;
    
    if (ptr->next != NULL) {
        ptr->next->prev = newNode;
    } else {
        tail = newNode;
    }
    
    ptr->next = newNode;
    printf("Inserted %d at position %d\n", data, pos);
}

void DeleteAtBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node* temp = head;
    printf("Deleted %d from beginning\n", head->data);
    
    if (head->next == NULL) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    
    free(temp);
}

void DeleteAtEnd() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node* temp = tail;
    printf("Deleted %d from end\n", tail->data);
    
    if (tail->prev == NULL) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    
    free(temp);
}

void DeleteAtPosition() {
    int pos;
    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);
    
    if (pos < 1 || head == NULL) {
        printf("Invalid position or list is empty\n");
        return;
    }
    
    if (pos == 1) {
        DeleteAtBegin();
        return;
    }
    
    struct node* ptr = head;
    for (int i = 1; i < pos && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    printf("Deleted %d from position %d\n", ptr->data, pos);
    
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    } else {
        tail = ptr->prev;
    }
    
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    
    free(ptr);
}

void Search() {
    int data;
    printf("Enter data to search: ");
    scanf("%d", &data);
    
    struct node* ptr = head;
    int pos = 1;
    
    while (ptr != NULL) {
        if (ptr->data == data) {
            printf("Data %d found at position %d\n", data, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    
    printf("Data %d not found\n", data);
}

void Update() {
    int data, newData;
    printf("Enter data to update: ");
    scanf("%d", &data);
    printf("Enter new data: ");
    scanf("%d", &newData);
    
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == data) {
            ptr->data = newData;
            printf("Updated %d to %d\n", data, newData);
            return;
        }
        ptr = ptr->next;
    }
    
    printf("Data %d not found\n", data);
}

void FreeList(struct node* ptr) {
    while (ptr != NULL) {
        struct node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at begin\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at begin\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display Linked List\n");
        printf("8. Display Linked List Reverse\n");
        printf("9. Search Data\n");
        printf("10. Update Data\n");
        printf("11. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
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
                FreeList(head);
                printf("Exiting... Memory freed.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);

    return 0;
}