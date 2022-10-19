#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} NODE;

NODE *createbst(NODE *roorNode, int value);
void inorder(NODE *node);
NODE *bstsearch(NODE *root, int value);
void printEmptyTreeMsg();
NODE *delbst(NODE *root, int value);
void checkAndsetParentNodeChildrens(NODE *parentNode, NODE *foundNode, NODE *childNode);

NODE *parentNode = NULL;

int main()
{
    int n, num, searchItem, deleteVal;
    NODE *rootNode = NULL, *holderNode;
    do
    {
        printf("\n\n******MENU******\n");
        printf("\n1. Insert data into a binary search tree");
        printf("\n2. In-order Traversal");
        printf("\n3. Search item in bst");
        printf("\n4. Delete item in bst");
        printf("\n5. Exit from the program");
        printf("\n\nEnter your option: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &num);
            rootNode = createbst(rootNode, num);
            break;
        case 2:
            if (rootNode != NULL)
            {
                inorder(rootNode);
            }
            else
            {
                printEmptyTreeMsg();
            }
            break;
        case 3:
            if (rootNode != NULL)
            {
                printf("Enter data to search: ");
                scanf("%d", &searchItem);
                holderNode = bstsearch(rootNode, searchItem);
                // holderNode = bstsearch(rootNode, searchItem, parentNode);
                if (holderNode != NULL)
                {
                    printf("\n%d has been found at memory location:  %p ", holderNode->data, holderNode);
                }
                else
                {
                    printf("\nSearch item has not been found in the tree.");
                }
            }
            else
            {
                printEmptyTreeMsg();
            }
            break;

        case 4:
            if (rootNode == NULL)
            {
                printEmptyTreeMsg();
            }
            else
            {

                printf("\nPlease enter the value to delete : ");
                scanf("%d", &deleteVal);
                rootNode = delbst(rootNode, deleteVal);
            }
            break;
        }
    } while (n != 5);
}

NODE *createbst(NODE *rootNode, int num)
{

    NODE *newNode, *ptr, *currentNode;
    if (rootNode == NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->data = num;
        rootNode = newNode;
        printf("BST is created.");
    }
    else
    {
        ptr = rootNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->right = NULL;
        newNode->left = NULL;
        newNode->data = num;
        while (1)
        {
            if (ptr->data <= num)
            {
                currentNode = ptr->right;
                if (currentNode == NULL)
                {
                    ptr->right = newNode;
                    break;
                }
                ptr = currentNode;
            }
            else if (ptr->data > num)
            {
                currentNode = ptr->left;
                if (currentNode == NULL)
                {
                    ptr->left = newNode;
                    break;
                }
                ptr = currentNode;
            }
        }
        printf("Data has been inserted into existing tree.");
    }
    return rootNode;
}

void inorder(NODE *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("\t%d", node->data);
        inorder(node->right);
    }
}

// NODE *bstsearch(NODE *rootNode, int value, NODE *parentNode)
NODE *bstsearch(NODE *rootNode, int value)
{
    NODE *tempNode = rootNode;
    parentNode = NULL;
    if (rootNode == NULL)
    {
        return NULL;
    }
    else if (rootNode->data == value)
    {
        return rootNode;
    }
    while (tempNode != NULL)
    {
        if (tempNode->data == value)
        {
            printf("parentNode: %d", parentNode->data);
            return tempNode;
        }
        else if (tempNode->data > value)
        {
            parentNode = tempNode;
            tempNode = tempNode->left;
        }
        else
        {
            parentNode = tempNode;
            tempNode = tempNode->right;
        }
    }
    return tempNode;
}

void printEmptyTreeMsg()
{
    printf("\nTree is empty.");
}

NODE *delbst(NODE *rootNode, int value)
{
    NODE *foundNode = NULL, *tempNode, *succesorParentNode = NULL;
    int flag = 0;
    foundNode = bstsearch(rootNode, value);

    // case 1: no matched item is there in BST
    if (foundNode == NULL)
    {
        printf("\nItem has not been found for delete in BST.");
    }
    // case 2 : No child
    else if (foundNode->right == NULL && foundNode->left == NULL)
    {
        // if target node is root node, then root node will be deleted.
        if (parentNode != NULL)
            checkAndsetParentNodeChildrens(parentNode, foundNode, NULL);
        else
            rootNode = NULL;
        free(foundNode);
        flag = 1;
    }
    // case 3 : Single child
    else if (foundNode->right == NULL || foundNode->left == NULL)
    {
        if (foundNode->right == NULL)
        {
            tempNode = foundNode->left;
        }
        else
        {
            tempNode = foundNode->right;
        }
        if (parentNode == NULL)
        {
            rootNode = tempNode;
        }
        else if (rootNode != tempNode)
            checkAndsetParentNodeChildrens(parentNode, foundNode, tempNode);
        free(foundNode);
        flag = 1;
    }
    // case 4: when target node has two children
    else if (foundNode->right != NULL && foundNode->left != NULL)
    {

        tempNode = foundNode->right;
        while (tempNode->left != NULL)
        {
            succesorParentNode = tempNode;
            tempNode = tempNode->left;
        }
        if (succesorParentNode == NULL)
        {
            foundNode->right = tempNode->right;
        }
        else
        {
            succesorParentNode->left = tempNode->right;
        }
        // override the value
        foundNode->data = tempNode->data;
        // free the extra node
        free(tempNode);
        flag = 1;
    }
    if (flag == 1)
        printf("\n%d has been deleted from the BST.", value);
    return rootNode;
}

void checkAndsetParentNodeChildrens(NODE *parentNode, NODE *foundNode, NODE *childNode)
{

    if (parentNode->left == foundNode)
    {
        parentNode->left = childNode;
    }
    else
    {
        parentNode->right = childNode;
    }
}