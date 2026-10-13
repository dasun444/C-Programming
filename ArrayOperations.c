#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100 // Maximum size allocated in memory

// Function Declarations
void traverse(int arr[], int size);
void insertAtFront(int arr[], int *size, int value);
void insertAtBack(int arr[], int *size, int value);
void insertAtPosition(int arr[], int *size, int position, int value);
void deleteFront(int arr[], int *size);
void deleteBack(int arr[], int *size);
void deleteAtPosition(int arr[], int *size, int position);
int searchByValue(int arr[], int size, int value);
void updateByIndex(int arr[], int size, int index, int newValue);
void updateByValue(int arr[], int size, int oldValue, int newValue);

int main() {
    int arr[MAX_CAPACITY] = {10, 20, 30, 40, 50}; // Initial array
    int size = 5; // Logical size tracking valid elements
    int choice, value, pos, index, oldValue;

    do {
        printf("\n================ ARRAY OPERATIONS ================\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Back\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Back\n");
        printf("6. Delete from Any Position\n");
        printf("7. Search Element by Value\n");
        printf("8. Update Element by Index\n");
        printf("9. Update Element by Value\n");
        printf("10. Display Array (Traverse)\n");
        printf("11. Exit\n");
        printf("==================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(arr, &size, value);
                break;

            case 2:
                printf("Enter value to insert at back: ");
                scanf("%d", &value);
                insertAtBack(arr, &size, value);
                break;

            case 3:
                printf("Enter position (0 to %d) to insert: ", size);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtPosition(arr, &size, pos, value);
                break;

            case 4:
                deleteFront(arr, &size);
                break;

            case 5:
                deleteBack(arr, &size);
                break;

            case 6:
                printf("Enter position (0 to %d) to delete: ", size - 1);
                scanf("%d", &pos);
                deleteAtPosition(arr, &size, pos);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                index = searchByValue(arr, size, value);
                if (index != -1) {
                    printf("Element %d found at index %d\n", value, index);
                } else {
                    printf("Element %d not found in the array\n", value);
                }
                break;

            case 8:
                printf("Enter index to update (0 to %d): ", size - 1);
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                updateByIndex(arr, size, index, value);
                break;

            case 9:
                printf("Enter old value to search and update: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &value);
                updateByValue(arr, size, oldValue, value);
                break;

            case 10:
                traverse(arr, size);
                break;

            case 11:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 11);

    return 0;
}

// 1. Traverse Array
void traverse(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nLogical Size: %d\n", size);
}

// 2. Insert at Front
void insertAtFront(int arr[], int *size, int value) {
    if (*size >= MAX_CAPACITY) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    // Shift elements one position to the right
    for (int index = *size - 1; index >= 0; index--) {
        arr[index + 1] = arr[index];
    }
    arr[0] = value;
    (*size)++; // Update logical size
    printf("Element inserted at front successfully\n");
}

// 3. Insert at Back
void insertAtBack(int arr[], int *size, int value) {
    if (*size >= MAX_CAPACITY) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    arr[*size] = value;
    (*size)++; // Update logical size
    printf("Element inserted at back successfully\n");
}

// 4. Insert at Any Position
void insertAtPosition(int arr[], int *size, int position, int value) {
    if (*size >= MAX_CAPACITY) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    if (position == *size) {
        arr[*size] = value;
    } else {
        // Shift elements to the right
        for (int index = *size - 1; index >= position; index--) {
            arr[index + 1] = arr[index];
        }
        arr[position] = value;
    }
    (*size)++;
    printf("Element inserted at position %d successfully\n", position);
}

// 5. Delete from Front
void deleteFront(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    // Shift elements to the left
    for (int index = 1; index < *size; index++) {
        arr[index - 1] = arr[index];
    }
    (*size)--; // Update logical size
    printf("Element deleted from front successfully\n");
}

// 6. Delete from Back
void deleteBack(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    (*size)--; // No shifting required, just decrease logical size
    printf("Element deleted from back successfully\n");
}

// 7. Delete from Any Position
void deleteAtPosition(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements left starting from the given position
    if (position < *size - 1) {
        for (int index = position + 1; index < *size; index++) {
            arr[index - 1] = arr[index];
        }
    }
    (*size)--;
    printf("Element deleted at position %d successfully\n", position);
}

// 8. Search Element by Value
int searchByValue(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i; // Return index when found
        }
    }
    return -1; // Return -1 if not found
}

// 9. Update Element by Index
void updateByIndex(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size) {
        printf("Invalid index!\n");
        return;
    }
    arr[index] = newValue;
    printf("Element at index %d updated successfully\n", index);
}

// 10. Update Element by Value
void updateByValue(int arr[], int size, int oldValue, int newValue) {
    int index = searchByValue(arr, size, oldValue);
    if (index == -1) {
        printf("Value %d not found in array!\n", oldValue);
        return;
    }
    arr[index] = newValue;
    printf("Value %d updated to %d at index %d successfully\n", oldValue, newValue, index);
}