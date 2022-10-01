#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *temp, *prvnode, *curnode, *nxtnode;
    int choice;
    head = 0;

    do
    {
        // creating new node
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == 0)
        {
            head = newnode;
            temp = newnode;
        }

        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? Type 0 or 1\n");
        scanf("%d", &choice);

    } while (choice);

    printf("\n");

    // Printing data present in linked list

    temp = head;

    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}