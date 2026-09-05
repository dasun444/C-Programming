void insertAtFront(int arr[], int *size, int value)
{
    int index;

    // Shift elements one position to the right
    for (index = *size - 1; index >= 0; index--)
    {
        arr[index + 1] = arr[index];
    }

    // Insert new value at the front
    arr[0] = value;

    // Update logical size
    (*size)++;

    printf("Element inserted at front successfully\n");
}





int main()
{
    int arr[10] = {10, 20, 30};
    int size = 3;
    int value = 5;

    insertAtFront(arr, &size, value);

    // Print updated array   
    printf("Array after insertion: ");
    for (int i = 0; i < size; i++)
    { 
        printf("%d ", arr[i]);
    }

    printf("\nLogical size: %d\n", size);

    return 0;
}
