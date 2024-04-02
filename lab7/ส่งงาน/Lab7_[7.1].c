#include <stdio.h>
#include <stdlib.h>    //Jedsadaporn pannok No.66070503410
#include <string.h>

// Create Node
struct Node {
    int key;            // Key value of the node
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
    int height;         // Height of the node in the tree
};

int max(int a, int b); // Function to return the maximum of two integers

// Calculate height of a node
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node with given key
struct Node *newNode(int key) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node)); // Allocate memory for the new node
    node->key = key; // Set the key value of the node
    node->left = NULL; // Initialize left child pointer as NULL
    node->right = NULL; // Initialize right child pointer as NULL
    node->height = 1; // Set height of the new node as 1
    return (node);
}
.k
// Right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left; // Store the left child of y as x
    struct Node *T2 = x->right; // Store the right child of x as T2

    // Perform rotation
    x->right = y; // Make y as the right child of x
    y->left = T2; // Make T2 as the left child of y

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1; // Update height of y
    x->height = max(height(x->left), height(x->right)) + 1; // Update height of x

    return x; // Return the new root of the rotated subtree
}

// Left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right; // Store the right child of x as y
    struct Node *T2 = y->left; // Store the left child of y as T2

    // Perform rotation
    y->left = x; // Make x as the left child of y
    x->right = T2; // Make T2 as the right child of x

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1; // Update height of x
    y->height = max(height(y->left), height(y->right)) + 1; // Update height of y

    return y; // Return the new root of the rotated subtree
}

// Get the balance factor of a node
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right); // Return the balance factor of the node
}

// Insert a node with given key in the AVL tree
struct Node *insertNode(struct Node *node, int key) {
    // Find the correct position to insert the node and insert it
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of the current node
    int balance = getBalance(node);

    // Perform rotations based on the balance factor
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the node with the minimum key value in a given subtree
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a node with given key from the AVL tree
struct Node *deleteNode(struct Node *root, int key) {
    // Base case
    if (root == NULL) {
        printf("Node not found.\n");
        return root;
    }

    // Search for the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found, check for children
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's key to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of the current node
    int balance = getBalance(root);

    // Perform rotations based on the balance factor
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Print the nodes of the AVL tree in preorder traversal
void printPreOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Main function
int main() {
    struct Node *root = NULL; // Initialize root of AVL tree as NULL

    char command[10]; // Variable to store user input command
    int key; // Variable to store user input key
    int exit_flag = 0; // Flag to control program exit

    // Main loop to process user commands
    while (!exit_flag) {
        scanf("%s", command); // Read user input command

        // Process commands
        if (strcmp(command, "INSERT") == 0) {
            // Insert nodes into the AVL tree
            while (scanf("%d", &key) == 1) {
                root = insertNode(root, key); // Call insertNode function to insert a node with the given key
            }
        } else if (strcmp(command, "PRINT") == 0) {
            // Print the nodes of the AVL tree
            if (root == NULL)
                printf("Tree is empty.");
            else
                printPreOrder(root); // Call printPreOrder function to print nodes in preorder traversal
            printf("\n");
        } else if (strcmp(command, "DELETE") == 0) {
            // Delete nodes from the AVL tree
            while (scanf("%d", &key) == 1) {
                root = deleteNode(root, key); // Call deleteNode function to delete a node with the given key
            }
        } else if (strcmp(command, "EXIT") == 0) {
            // Exit the program
            exit_flag = 1;
        } else {
            // Invalid command
            printf("Invalid command.\n");
            // Clear input buffer
            while (getchar() != '\n');
        }
    }

    return 0; // Return from main function
}
