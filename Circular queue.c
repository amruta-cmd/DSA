#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert operation
void insert()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("\nQueue Overflow! Queue is full.\n");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = value;
        printf("%d inserted successfully.\n", value);
    }
}

// Delete operation
void delete()
{
    if (front == -1)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
    }
    else
    {
        printf("\nDeleted element: %d\n", queue[front]);

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

// Display operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        printf("\nCircular Queue elements are: ");

        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        printf("\n");
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

