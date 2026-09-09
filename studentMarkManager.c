/*
Applied Problem: Student Marks Manager
Build a small console application, marksmanager, that manages an array of up to 100 student marks
(integers) and offers a menu:
(a) Add a mark at a chosen position
(b) Delete a mark at a chosen position
(c) Search for a mark (report all matching indices)
(d) Update a mark by index
(e) Display all marks
(f) Exit
Re-use the functions you wrote above. The program should loop, showing the menu, until the
user chooses Exit. Make sure overflow/underflow/invalid-index messages are shown to the user
rather than crashing.

*/

#include <stdio.h>
#define CAPACITY 100

void insertAt(int arr[], int *size, int position, int value) {
    if (*size >= CAPACITY) {
        printf("-> Overflow Error: The list is full (capacity 100). Cannot add.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("-> Error: Invalid position. Position must be between 0 and %d.\n", *size);
        return;
    }
    
   
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = value;
    (*size)++;
    printf("-> Mark '%d' added successfully at position %d.\n", value, position);
}

void deleteAt(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("-> Underflow Error: The list is empty. Cannot delete.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("-> Error: Invalid position. Position must be between 0 and %d.\n", *size - 1);
        return;
    }
    
    for (int i = position + 1; i < *size; i++) {
        arr[i - 1] = arr[i];
    }
    (*size)--;
    printf("-> Mark deleted successfully from position %d.\n", position);
}

void search(int arr[], int size, int value) {
    if (size == 0) {
        printf("-> The list is empty.\n");
        return;
    }
    
    int found = 0;
    printf("-> Searching for mark '%d': ", value);
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("[Index %d] ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Not found in the array.");
    }
    printf("\n");
}

void update(int arr[], int size, int position, int newValue) {
    if (size == 0) {
        printf("-> The list is empty. Nothing to update.\n");
        return;
    }
    if (position < 0 || position >= size) {
        printf("-> Error: Invalid index. Must be between 0 and %d.\n", size - 1);
        return;
    }
    arr[position] = newValue;
    printf("-> Mark at index %d updated to '%d'.\n", position, newValue);
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("-> The list is currently empty.\n");
        return;
    }
    printf("-> Current Marks: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int marks[CAPACITY];
    int size = 0;
    char choice;
    int position, value;

    printf("-> Welcome to Marks Manager \n");

    do {
        printf("\nMenu:\n");
        printf("(a) Add a mark at a chosen position\n");
        printf("(b) Delete a mark at a chosen position\n");
        printf("(c) Search for a mark\n");
        printf("(d) Update a mark by index\n");
        printf("(e) Display all marks\n");
        printf("(f) Exit\n");
        printf("Enter your choice: ");
        
        scanf(" %c", &choice); 

        switch (choice) {
            case 'a':
            case 'A':
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &position);
                printf("Enter mark to add: ");
                scanf("%d", &value);
                insertAt(marks, &size, position, value);
                break;
                
            case 'b':
            case 'B':
                printf("Enter position to delete (0 to %d): ", size > 0 ? size - 1 : 0);
                scanf("%d", &position);
                deleteAt(marks, &size, position);
                break;
                
            case 'c':
            case 'C':
                printf("Enter mark to search for: ");
                scanf("%d", &value);
                search(marks, size, value);
                break;
                
            case 'd':
            case 'D':
                printf("Enter index to update (0 to %d): ", size > 0 ? size - 1 : 0);
                scanf("%d", &position);
                printf("Enter the new mark: ");
                scanf("%d", &value);
                update(marks, size, position, value);
                break;
                
            case 'e':
            case 'E':
                display(marks, size);
                break;
                
            case 'f':
            case 'F':
                printf("Exiting Marks Manager. Goodbye!\n");
                break;
                
            default:
                printf("-> Error: Invalid choice. Please select an option from a to f.\n");
        }
    } while (choice != 'f' && choice != 'F');

    return 0;
}