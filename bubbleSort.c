#include <stdio.h>

void bubbleSort(int arr[], int n){

    int i,j,temp;
    for ( i=0 ; i < n-1 ; i++)
    {
        for ( j=0 ; j < n-1-i;j++ )
        {
            if(arr[j] >arr[j+1]){
               temp= arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp; 
            }
        }
    }
}



int main (){

    int arr[]={7,3,2,5,4};
    int n = sizeof(arr)/sizeof(0);
    printf("UnSorted array  \n");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    bubbleubbleSort(arr,n);
    printf("Sorted array - Bubble sort\n");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
} 