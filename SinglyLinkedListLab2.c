#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

struct LinkedList *createList() {
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
        list->head = NULL;
        list->tail = NULL;
    return list;
}

void insertFront(struct LinkedList *list, int value) {
    struct Node *newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
}

void traverse(struct LinkedList *list) {
    if (list->head == NULL) {
        printf("Empty List\n");
    } else {
        struct Node *temp = list->head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insertRear(struct LinkedList *list, int value) {
    struct Node *newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void insertAtPosition(struct LinkedList *list, int position, int value) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    } else if (position == 1) {
        insertFront(list, value);
        return;
    }

    struct Node *temp = list->head;
    int i = 1;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    } else if (temp->next == NULL) {
        insertRear(list, value);
        return;
    } else {
        struct Node *newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
}

int search(struct LinkedList *list, int value) {
    if (list->head == NULL) {
        printf("Empty List\n");
        return -1;
    }
    
    struct Node *temp = list->head;
    int position = 1;
    
    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1;
}

int update(struct LinkedList *list, int oldValue, int newValue) {
    if (list->head == NULL) {
        printf("Empty List\n");
        return 0;
    }
    
    struct Node *temp = list->head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

int deleteNode(struct LinkedList* list, int value) {
    if (list->head == NULL) {
        return 0;
    }

    struct Node *temp = list->head;
    struct Node *prev = NULL;

    if (temp->data == value) {
        list->head = temp->next;
        
        if (list->head == NULL) {
            list->tail = NULL;
        }
        
        free(temp); 
        return 1;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return 0;
    }

    prev->next = temp->next;

    if (temp == list->tail) {
        list->tail = prev;
    }

    free(temp);
    return 1;
}

int main() {
    struct LinkedList *list1 = createList();
    insertFront(list1, 10);
    traverse(list1);
    insertFront(list1, 20);
    insertRear(list1, 30);
    traverse(list1);
    insertAtPosition(list1, 1, 40);
    insertAtPosition(list1, 2, 35);
    insertAtPosition(list1, 5, 55);
    traverse(list1);
    insertAtPosition(list1, 7, 45);
    insertAtPosition(list1, 12, 45);
    traverse(list1);
    insertAtPosition(list1, -2, 45);
    traverse(list1);

    insertFront(list1, 20);
    insertRear(list1, 30);
    insertAtPosition(list1, 1, 40);
    traverse(list1);

    int position = search(list1, 35);
    if (position != -1) {
        printf("Value found at %d\n", position);
    } else {
        printf("Value not found\n");
    }

    int update_result = update(list1, 45, 90);
    if (update_result == 1) {
        printf("Value updated\n");
    } else {
        printf("Value not found\n");
    }

    traverse(list1);

int delete_result = deleteNode(list1, 30);
    if (delete_result == 1) {
        printf("Node deleted successfully.\n");
    } else {
        printf("Value not found for deletion.\n");
    }
    int missing_delete = deleteNode(list1, 999);
    if (missing_delete == 1) {
        printf("Node deleted successfully.\n");
    } else {
        printf("Value not found for deletion.\n");
    }

    traverse(list1);
    return 0;
}
