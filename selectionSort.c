#include <stdio.h>
void selectionSort(int arr[],int n){
    int i,j,minI,temp;
    for (i = 0;i<n-1;i++){
        minI=i;
        for (j=i+1 ; j<n;j++){
            if(arr[j]<arr[minI]){
                minI = j ;
            }
        }

        temp= arr[i];
        arr[i]=arr[minI];
        arr[minI]=temp;
    }

}




int main (){

    int arr[]={7,4,5,9,8,2,1};
    int  n =sizeof(arr)/sizeof(int);
    printf("UnSorted array  \n");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    selectionSort(arr,n);
    printf("Sorted array - Selection sort\n");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}