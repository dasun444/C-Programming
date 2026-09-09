/*
Assume an array has a fixed capacity capacity and currently contains size elements (size > 0).
Write a C function: void deleteAt(int arr[], int *size, int position) that deletes
the element at the given position (0 ≤ position < *size).
Your function should:
- Check whether the array is empty. If it is empty, print an underflow message and do not
modify the array.
- Check whether the given position is valid. If the position is invalid, print an appropriate
message and do not modify the array.
- Shift the required elements one position to the left to fill the empty space.
- Update size using the pointer after a successful deletion.
void deleteAt (int arr [] , int * size , int position ){
// TODO
}

*/


#include <stdio.h>

void deleteAt(int arr[], int *size, int position){

    if (*size <= 0) {
        printf("Underflow: The array is empty. Cannot delete.\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Error: Invalid position. Position must be between 0 and %d.\n", *size - 1);
        return;
    }

    
    for( int i = position + 1;i<*size;i++){
        arr[i -1] = arr[i];
    }

    (*size)--;
}



int main(){

    int arr[8]={10,20,30,40,50};
    int size = 5; 
    int capacity = 8;

    printf("Before Deletion: \n");
    for(int i =0;i<size;i++){
        printf("index %d th element is %d \n",i,arr[i]);
    }

    printf("\n\nAfter Deletion: \n");
    deleteAt(arr,&size,2);

    for(int i =0;i<size;i++){
        printf("index %d th element is %d \n",i,arr[i]);
    }

return 0;
}