#include <stdio.h>

#define ROWS 6
#define COLS 8

// Function declarations
void initializeParking(int parking[ROWS][COLS]);
void displayParking(int parking[ROWS][COLS]);
int countAvailableSpaces(int parking[ROWS][COLS]);
void parkVehicle(int parking[ROWS][COLS], int row, int col);
void removeVehicle(int parking[ROWS][COLS], int row, int col);
void rowWithMostEmpty(int parking[ROWS][COLS]);
void checkConsecutiveEmpty(int parking[ROWS][COLS]);
void bestParkingSlot(int parking[ROWS][COLS]);

int main()
{
    int parking[ROWS][COLS];
    int choice, row, col;

    initializeParking(parking);

    do
    {
        printf("\n===== PARKING MANAGEMENT SYSTEM =====\n");
        printf("1. Display Parking Layout\n");
        printf("2. Park Vehicle\n");
        printf("3. Remove Vehicle\n");
        printf("4. Count Available Spaces\n");
        printf("5. Find Row with Most Empty Slots\n");
        printf("6. Check Consecutive Empty Slots\n");
        printf("7. Suggest Best Parking Slot\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayParking(parking);
                break;

            case 2:
                printf("Enter row (0-5): ");
                scanf("%d", &row);

                printf("Enter column (0-7): ");
                scanf("%d", &col);

                parkVehicle(parking, row, col);
                break;

            case 3:
                printf("Enter row (0-5): ");
                scanf("%d", &row);

                printf("Enter column (0-7): ");
                scanf("%d", &col);

                removeVehicle(parking, row, col);
                break;

            case 4:
                printf("Available spaces = %d\n",
                       countAvailableSpaces(parking));
                break;

            case 5:
                rowWithMostEmpty(parking);
                break;

            case 6:
                checkConsecutiveEmpty(parking);
                break;

            case 7:
                bestParkingSlot(parking);
                break;

            case 8:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 8);

    return 0;
}

// Initialize parking area
void initializeParking(int parking[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            parking[i][j] = 0;
        }
    }

    // Reserved VIP slots
    parking[0][0] = 2;
    parking[0][1] = 2;
}

// Display parking layout
void displayParking(int parking[ROWS][COLS])
{
    int i, j;

    printf("\nParking Layout\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%d ", parking[i][j]);
        }
        printf("\n");
    }

    printf("\n0 = Empty | 1 = Occupied | 2 = VIP Reserved\n");
}

// Count available spaces
int countAvailableSpaces(int parking[ROWS][COLS])
{
    int i, j, count = 0;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(parking[i][j] == 0)
            {
                count++;
            }
        }
    }

    return count;
}

// Park vehicle
void parkVehicle(int parking[ROWS][COLS], int row, int col)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        if(parking[row][col] == 0)
        {
            parking[row][col] = 1;
            printf("Vehicle parked successfully.\n");
        }
        else if(parking[row][col] == 2)
        {
            printf("VIP Reserved Slot!\n");
        }
        else
        {
            printf("Slot already occupied.\n");
        }
    }
    else
    {
        printf("Invalid slot position.\n");
    }
}

// Remove vehicle
void removeVehicle(int parking[ROWS][COLS], int row, int col)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        if(parking[row][col] == 1)
        {
            parking[row][col] = 0;
            printf("Vehicle removed successfully.\n");
        }
        else
        {
            printf("No vehicle found in this slot.\n");
        }
    }
    else
    {
        printf("Invalid slot position.\n");
    }
}

// Find row with most empty slots
void rowWithMostEmpty(int parking[ROWS][COLS])
{
    int i, j;
    int maxRow = 0;
    int maxEmpty = 0;

    for(i = 0; i < ROWS; i++)
    {
        int emptyCount = 0;

        for(j = 0; j < COLS; j++)
        {
            if(parking[i][j] == 0)
            {
                emptyCount++;
            }
        }

        if(emptyCount > maxEmpty)
        {
            maxEmpty = emptyCount;
            maxRow = i;
        }
    }

    printf("Row %d has the most empty slots (%d slots).\n",
           maxRow, maxEmpty);
}

// Detect consecutive empty slots
void checkConsecutiveEmpty(int parking[ROWS][COLS])
{
    int i, j;
    int found = 0;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS - 1; j++)
        {
            if(parking[i][j] == 0 &&
               parking[i][j + 1] == 0)
            {
                printf("Consecutive empty slots found at Row %d, Columns %d and %d\n",
                       i, j, j + 1);

                found = 1;
            }
        }
    }

    if(found == 0)
    {
        printf("No consecutive empty slots available.\n");
    }
}

// Suggest best parking slot nearest to entrance
void bestParkingSlot(int parking[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(parking[i][j] == 0)
            {
                printf("Best parking slot: Row %d, Column %d\n",
                       i, j);
                return;
            }
        }
    }

    printf("No empty slots available.\n");
}