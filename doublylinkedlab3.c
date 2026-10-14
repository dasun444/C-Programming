/*Student Ranking System
Problem Description
A university maintains a student ranking system for a competition. Student result records
are received one by one. Each student record contains:
• Student ID
• Student Name
• Marks
Since students are added continuously, the system should store student records dynamically.
The system should support:
1. Adding students when results arrive.
2. Displaying student records from the beginning to the end.
3. Displaying student records from the end to the beginning.
4. Sorting students according to their marks to generate rankings.
You are required to design this system using a Doubly Linked List*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int marks;
 
    struct Student *prev;
    struct Student *next;
};

struct Student *createStudent(int id, char name[], int marks) {
    struct Student *newNode = malloc(sizeof(struct Student));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->marks = marks;

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

struct StudentList {
    struct Student *head;
    struct Student *tail;
};

struct StudentList *createStudentList() {
    struct StudentList *newList = malloc(sizeof(struct StudentList));
    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

void insertStudent(struct StudentList *list, int id, char name[], int marks) {
    struct Student *newStudent = createStudent(id, name, marks);
    if (list->head == NULL) {
        list->head = newStudent;
        list->tail = newStudent;
    } else {
        newStudent->prev = list->tail;
        list->tail->next = newStudent;
        list->tail = newStudent;
    }
}

void displayForward(struct StudentList *list) {
    if (list->head == NULL) {
        printf("Empty List\n");
        return;
    } else {
        struct Student *temp = list->head;

        while (temp != NULL) {
            printf("%d %s %d -> ", temp->id, temp->name, temp->marks);
            temp = temp->next;
        }
        printf("End of List\n");
    }
}

void displayBackward(struct StudentList *list) {
    if (list->tail == NULL) {
        printf("Empty List\n");
        return;
    } else {
        struct Student *temp = list->tail;

        while (temp != NULL) {
            printf("%d %s %d -> ", temp->id, temp->name, temp->marks);
            temp = temp->prev;
        }
        printf("End of List\n");
    }
}

int getSize(struct StudentList *list) {
    if (list->head == NULL) {
        return 0;
    } else {
        struct Student *temp = list->head;
        int size = 0;

        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }
}

void swapStudent(struct Student *left, struct Student *right) {
    int tempid = left->id;
    left->id = right->id;
    right->id = tempid;

    int tempmarks = left->marks;
    left->marks = right->marks;
    right->marks = tempmarks;

    char tempname[50];
    strcpy(tempname, left->name);
    strcpy(left->name, right->name);
    strcpy(right->name, tempname);
}

// Original Bubble Sort
void bubbleSort(struct StudentList *list) {
    if (list->head == NULL) {
        printf("Empty List\n");
        return;
    }
    int size = getSize(list);
    struct Student *current;
    if (size <= 1) {
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        current = list->head;
        for (int j = 0; j < size - i - 1; j++) {
            if (current->marks < current->next->marks) {
                swapStudent(current, current->next);
            }
            current = current->next;
        }
    }
}

// Optimized Bubble Sort (Task 8.1)
void optimizedBubbleSort(struct StudentList *list) {
    if (list->head == NULL) {
        printf("Empty List\n");
        return;
    }
    int size = getSize(list);
    if (size <= 1) {
        return;
    }

    int swapped;
    struct Student *current;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0; // Reset swap flag for this pass
        current = list->head;

        for (int j = 0; j < size - i - 1; j++) {
            if (current->marks < current->next->marks) {
                swapStudent(current, current->next);
                swapped = 1; // A swap occurred
            }
            current = current->next;
        }

        // If no elements were swapped during this pass, the list is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    struct StudentList *list;

    list = createStudentList();

    insertStudent(list, 101, "Amal", 78);
    insertStudent(list, 102, "Ravi", 65);
    insertStudent(list, 103, "Nimal", 90);
    insertStudent(list, 104, "Saman", 55);
    insertStudent(list, 105, "John", 78);

    printf("\nStudent Record Forward:\n");
    displayForward(list);

    printf("\nStudent Record Backward:\n");
    displayBackward(list);

    printf("\nNumber of Students: %d\n", getSize(list));

    printf("\nBefore Sorting:\n");
    displayForward(list);

    // Using the Optimized Bubble Sort implementation
    optimizedBubbleSort(list);

    printf("\nAfter Optimized Sorting (Highest to Lowest Marks):\n");
    displayForward(list);

    return 0;
}
