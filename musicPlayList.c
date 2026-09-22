/*
Adapt the Linked List for a Music Playlist
Modify the previously implemented singly linked list functions to create a simple music
playlist manager. Instead of storing integer values, each node should store a song title.
The existing linked list operations should be adapted to support playlist management while
maintaining the same linked list logic.
The playlist should store songs in their playing order, with positions starting from 1.
Complete the following tasks:
1. Explain in 2–3 sentences why a singly linked list is more suitable than an array for
managing a playlist that frequently changes. Consider insertion, deletion, and dynamic
size.
2. Modify the node structure and related functions to store song titles instead of integer
values.
3. Implement addSong(position, title) to insert a song title at any valid 1-indexed
position.
4. Implement removeSong(position) to remove a song from the specified playlist position.
5. Implement displayPlaylist() to display all songs in their playing order.
6. Using the implemented functions, simulate the following operations and display the
playlist after each step:
• Add “Song A” at position 1.
• Add “Song B” at position 2.
• Add “Song C” at position 2.
• Remove the song at position 1.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for storing song titles
struct Node {
    char title[100];
    struct Node *next;
};

// Playlist structure maintaining head and tail references
struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

// Create a new song node
struct Node *createNode(char *title) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->title, title);
    newNode->next = NULL;
    return newNode;
}

// Create an empty playlist
struct LinkedList *createPlaylist() {
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Display all songs in their playing order
void displayPlaylist(struct LinkedList *list) {
    if (list->head == NULL) {
        printf("Playlist is Empty\n");
    } else {
        struct Node *temp = list->head;
        int pos = 1;
        while (temp != NULL) {
            printf("%d. %s -> ", pos, temp->title);
            temp = temp->next;
            pos++;
        }
        printf("NULL\n");
    }
}

// Add a song at any valid 1-indexed position
void addSong(struct LinkedList *list, int position, char *title) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    struct Node *newNode = createNode(title);
    
    // Insertion at the front (position 1)
    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
        if (list->tail == NULL) {
            list->tail = newNode;
        }
        return;
    }

    struct Node *temp = list->head;
    int i = 1;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
    // Update tail if inserted at the very end
    if (newNode->next == NULL) {
        list->tail = newNode;
    }
}

// Remove a song from the specified playlist position
void removeSong(struct LinkedList *list, int position) {
    if (list->head == NULL || position <= 0) {
        printf("Invalid deletion or empty playlist\n");
        return;
    }

    struct Node *temp = list->head;

    // Deleting the first node
    if (position == 1) {
        list->head = temp->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    int i = 1;
    while (temp != NULL && i < position) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    
    // Update tail if the last node is removed
    if (temp == list->tail) {
        list->tail = prev;
    }
    
    free(temp);
}




int main() {
    struct LinkedList *playlist = createPlaylist();

    // 1. Add "Song A" at position 1.
    printf("Step 1: Add \"Song A\" at position 1\n");
    addSong(playlist, 1, "Song A");
    displayPlaylist(playlist);
    printf("\n");

    // 2. Add "Song B" at position 2.
    printf("Step 2: Add \"Song B\" at position 2\n");
    addSong(playlist, 2, "Song B");
    displayPlaylist(playlist);
    printf("\n");

    // 3. Add "Song C" at position 2.
    printf("Step 3: Add \"Song C\" at position 2\n");
    addSong(playlist, 2, "Song C");
    displayPlaylist(playlist);
    printf("\n");

    // 4. Remove the song at position 1.
    printf("Step 4: Remove the song at position 1\n");
    removeSong(playlist, 1);
    displayPlaylist(playlist);

    return 0;
}