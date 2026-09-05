#include <stdio.h>

void insertAfterValue(int arr[], int *size, int prevValue, int newValue)
{
    int index = -1;

    // Find the previous value
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] == prevValue)
        {
            index = i;
            break;
        }
    }

    // If value not found
    if (index == -1)
    {
        printf("Previous value not found\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size - 1; i > index; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Insert new value
    arr[index + 1] = newValue;

    // Update logical size
    (*size)++;

    printf("Element inserted successfully\n");
}

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;

    insertAfterValue(arr, &size, 30, 35);

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
