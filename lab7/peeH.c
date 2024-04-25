#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} tree;

// Function to calculate the height of a node
int height(tree *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

// Helper function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new node with given data
tree *createNode(int data)
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to perform a left rotation
tree *Lrotate(tree *node)
{
    tree *T1 = node->left;
    tree *T2 = node->right;

    T1->right = node;
    node->left = T2;

    node->height = height(node);
    T1->height = height(T1);

    return T1;
}

// Function to perform a right rotation
tree *Rrotate(tree *node)
{
    tree *T1 = node->left;
    tree *T2 = node->right;

    T2->left = node;
    node->right = T2;

    node->height = height(node);
    T2->height = height(T2);

    return T2;
}

// Function to find the balance factor of a node (height(left) - height(right))
int balanceFactor(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}

// Function to insert a new node into the BST
tree *insert(tree *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = balanceFactor(root);

    if (balance > 1 && data < root->left->data)
    {
        return Rrotate(root);
    }
    if (balance < -1 && data > root->right->data)
    {
        return Lrotate(root);
    }
    if (balance > 1 && data > root->left->data)
    {
        root->left = Lrotate(root->left);
        return Rrotate(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = Rrotate(root->right);
        return Lrotate(root);
    }

    return root;
}

// Function to find the minimum value in the BST
tree *minValue(tree *root)
{
    tree *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node with given data from the BST
tree *deleteNode(tree *root, int data)
{
    if (root == NULL)
    {
        printf("Node not found");
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            tree *temp = (root->left) ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
                free(temp);
            }
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        else
        {
            tree *temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
    {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->left) >= 0)
    {
        return Rrotate(root);
    }
    if (balance > 1 && balanceFactor(root->left) < 0)
    {
        root->left = Lrotate(root->left);
        return Rrotate(root);
    }
    if (balance < -1 && balanceFactor(root->right) <= 0)
    {
        return Lrotate(root);
    }
    if (balance < -1 && balanceFactor(root->right) > 0)
    {
        root->right = Rrotate(root->right);
        return Lrotate(root);
    }

    return root;
}

// Function to perform a pre-order traversal of the BST
void preOrder(tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(void)
{
    tree *root = NULL;
    int tempData;
    char operand[10];

    while (1)
    {

        scanf("%s", operand);

        // INSERT
        if (strcmp(operand, "INSERT") == 0)
        {
            while (scanf("%d", &tempData) == 1)
            {

                root = insert(root, tempData);
            }
        }
        else if (strcmp(operand, "DELETE") == 0)
        {
            while (1)
            {

                if (scanf("%d", &tempData) == 1)
                {
                    root = deleteNode(root, tempData);
                }
                else
                {
                    break; // Exit the loop when non-integer input is encountered
                }
            }
        }
        else if (strcmp(operand, "PRINT") == 0)
        {
            preOrder(root);
            printf("\n");
        }
        else if (strcmp(operand, "EXIT") == 0)
        {
            free(root);
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}