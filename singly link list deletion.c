#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }
}

void deleteFirst()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("First element deleted successfully.\n");
    }
}

void deleteSpecified()
{
    struct node *temp, *prev;
    int value;

    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &value);

    temp = head;

    if(head->data == value)
    {
        head = head->next;
        free(temp);
        printf("Element deleted successfully.\n");
        return;
    }

    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element not found!\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);

        printf("Element deleted successfully.\n");
    }
}

void deleteLast()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("Last element deleted successfully.\n");
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);

        printf("Last element deleted successfully.\n");
    }
}

void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;

        printf("Linked List: ");

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Create List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteSpecified();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
