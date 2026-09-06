/*
(a) Write a program to display following data as a singly linked list
0 1 2 3 4
*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

void insert(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Display() {
    struct node* temp = head;
    printf("\n head=>");
    while (temp != NULL) {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" [null]\n");
}

int main() {
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(0);

    Display();
    return 0;
}