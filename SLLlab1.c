/*1) Take the following values as array elements
        10 14 20 34 45 8 4 3 23
    i) Insert 12 into the 3 rd position of the array(Index 2)
    ii) Delete the array element 8 from the array(Index 5)*/


#include <stdio.h>

void insertAnyPosition(int arr[],int *size,int position,int value){

    if(position <0 || position>*size)
    {
    printf("Invalid position.\n");
    return;
    }
    
    if(position==*size)
    {
    arr[*size]=value;//insert at back
    }
    else
    {
    for(int index=*size-1;index>=position;index--)
    {
        arr[index + 1]=arr[index];
    } 
    arr[position]=value;
    }

    (*size)++;

    printf("\nElement %d inserted at position %d successfully.\n",value,position);

}



void deleteAtAnyPosition(int arr[],int *size,int position)
{
    int index;
    if (position<*size-1)
    {
        for(index=position+1;index<*size;index++)
        {
            arr[index-1]=arr[index];
        }
    }
    arr[*size-1]=0;

    (*size)--;
    
    printf("\n\nElement deleted at position %d successfully.",position);

}



int main(){

int arr[15]={10, 14, 20, 34, 45, 8, 4, 3, 23};
int size=9;

printf("before insert: ");
for(int i=0;i<9;i++)
{
    printf("%d ",arr[i]);
}

insertAnyPosition(arr,&size,2,12);

    printf("after insert: ");
    for(int i=0;i<10;i++)
    {
    printf("%d ",arr[i]);
    }

    printf("\n\nbefore delete: ");
    for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
    }


deleteAtAnyPosition(arr,&size,6);

    printf("\nafter delete: ");

    for(int i=0;i<10;i++)
    {
    printf("%d ",arr[i]);
    }

return 0;
}