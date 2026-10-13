#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure implementation according to slides
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// LinkedList structure to wrap head and tail
struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

// Helper Functions
struct Node* create_node(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initialize_list(struct LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool is_empty(struct LinkedList *list) {
    return list->head == NULL;
}

// 1. Insert at Begin (insert_front)
void InsertAtBegin(struct LinkedList *list) {
    int value;
    printf("Enter data to add at the Begin: ");
    scanf("%d", &value);

    struct Node *newNode = create_node(value);

    if (is_empty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    printf("Node Added to the Begin!\n\n");
}

// 2. Insert at End (insert_rear)
void InsertAtEnd(struct LinkedList *list) {
    int value;
    printf("Enter data to add at the End: ");
    scanf("%d", &value);

    struct Node *newNode = create_node(value);

    if (is_empty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    printf("Node Added to the End!\n\n");
}

// 3. Insert at Position (insert_middle)
void InsertAtPosition(struct LinkedList *list) {
    if (is_empty(list)) {
        InsertAtBegin(list);
        return;
    }

    int pos, value;
    printf("Enter position to add data: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position! Enter a valid position!\n\n");
        return;
    }

    if (pos == 1) {
        InsertAtBegin(list);
        return;
    }

    printf("Enter data to add: ");
    scanf("%d", &value);

    struct Node *temp = list->head;
    int i = 1;

    // Traversal to position-1
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position! Out of bounds.\n\n");
        return;
    }

    if (temp->next == NULL) {
        // Equivalent to inserting at the end
        struct Node *newNode = create_node(value);
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
        printf("Node Added to position %d!\n\n", pos);
        return;
    }

    struct Node *newNode = create_node(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("Node Added to position %d!\n\n", pos);
}

// 4. Delete at Begin (delete_front)
void DeleteAtBegin(struct LinkedList *list) {
    if (is_empty(list)) {
        printf("Linked List is empty! Nothing to delete!\n\n");
        return;
    }

    struct Node *temp = list->head;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }

    free(temp);
    printf("Front Node Deleted!\n\n");
}

// 5. Delete at End (delete_rear)
void DeleteAtEnd(struct LinkedList *list) {
    if (is_empty(list)) {
        printf("Linked List is empty! Nothing to delete!\n\n");
        return;
    }

    struct Node *temp = list->tail;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }

    free(temp);
    printf("Rear Node Deleted!\n\n");
}

// 6. Delete at Position (delete_middle)
void DeleteAtPosition(struct LinkedList *list) {
    if (is_empty(list)) {
        printf("Linked List is empty! Nothing to delete!\n\n");
        return;
    }

    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position! Enter a valid position!\n\n");
        return;
    }

    if (pos == 1) {
        DeleteAtBegin(list);
        return;
    }

    struct Node *temp = list->head;
    int i = 1;

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position! Out of bounds.\n\n");
        return;
    }

    if (temp == list->tail) {
        DeleteAtEnd(list);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    printf("Node Deleted at position %d!\n\n", pos);
}

// 7. Display Linked List (traverse_forward)
void Display(struct LinkedList *list) {
    if (is_empty(list)) {
        printf("List is empty\n\n");
        return;
    }

    printf("Doubly Linked List Forward: ");
    struct Node *temp = list->head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

// 8. Display Reversed (traverse_backward)
void DisplayReverse(struct LinkedList *list) {
    if (is_empty(list)) {
        printf("List is empty\n\n");
        return;
    }

    printf("Doubly Linked List Reversed: ");
    struct Node *temp = list->tail;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n\n");
}

// 9. Search data
void Search(struct LinkedList *list) {
    if (is_empty(list)) {
        printf("List is empty\n\n");
        return;
    }

    int key;
    printf("Enter data to search: ");
    scanf("%d", &key);

    struct Node *temp = list->head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Data found at position %d in the list.\n\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Data not in the list\n\n");
}

// 10. Update data
void Update(struct LinkedList *list) {
    if (is_empty(list)) {
        printf("List is empty\n\n");
        return;
    }

    int key, newValue;
    printf("Enter existing data value to update: ");
    scanf("%d", &key);

    struct Node *temp = list->head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Enter new value: ");
            scanf("%d", &newValue);
            temp->data = newValue;
            printf("Node Updated successfully!\n\n");
            return;
        }
        temp = temp->next;
    }

    printf("Key not found in the list!\n\n");
}

// Free memory on exit
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct LinkedList list;
    initialize_list(&list);

    int choice;

    do {
        printf("\n1.Insert at begin\n2.Insert at end\n3.Insert at position\n4.Delete at begin\n5.Delete at end\n6.Delete at position\n7.Display linked List\n8.Display Linked List(Reversed)\n9.Search data\n10.Update\n11.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                InsertAtBegin(&list);
                break;
            case 2:
                InsertAtEnd(&list);
                break;
            case 3:
                InsertAtPosition(&list);
                break;
            case 4:
                DeleteAtBegin(&list);
                break;
            case 5:
                DeleteAtEnd(&list);
                break;
            case 6:
                DeleteAtPosition(&list);
                break;
            case 7:
                Display(&list);
                break;
            case 8:
                DisplayReverse(&list);
                break;
            case 9:
                Search(&list);
                break;
            case 10:
                Update(&list);
                break;
            case 11:
                freeList(list.head);
                printf("Memory cleared. Exiting...\n");
                exit(0);
            default:
                printf("Invalid Operation\n\n");
                break;
        }
    } while (choice != 11);

    return 0;
}