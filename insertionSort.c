#include <stdio.h>
void insertionSort(int arr[],int n){
    int i,j,key;
    for (i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while( j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
    arr[j+1]=key;

    }

}

int main (){

    int arr[]={4,3,2,7,6,10};
    int n = sizeof(arr)/sizeof(0);
    printf("UnSorted array  \n");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    insertionSort(arr,n);
    printf("Sorted array - Insertion sort\n");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}