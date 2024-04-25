// The Binary Search Tree
// A binary search tree is a special binary tree that the left child of a node has a value less than the node’s value and the right child has a value greater than the node’s value.

// It is efficient in inserting and it is used for sorting elements.

// Your task is to create a Binary Search Tree by using these commands:

// INS 
// �
// x: To insert the node with value 
// �
// x in a Binary Search Tree
// PREORDER: Print all the nodes in the tree by using Pre-order traversal
// INORDER: Print all the nodes in the tree by using In-order traversal
// POSTORDER: Print all the nodes in the tree by using Post-order traversal
// END: To print all the nodes in a binary search tree in sorted order and then terminate the program.
// All value in the binary tree will be guarunteed distinct. And there will be at least one node in the BST.

// Input
// The input consists of several lines
// The command and the value associated with the command (You can see examples for clarification). End the input section with command END

// Output
// The output section is dependent with the input as the traversal of the BST.
// The last line will print out all nodes in BST in sorted order.

// Example of input and output
// Input	Output
// INS 100
// INS 20
// INS 30
// INS 10
// INS 200
// INS 300
// INORDER
// INS 150
// PREORDER
// POSTORDER
// END	
// 10 20 30 100 200 300
// 100 20 10 30 200 150 300
// 10 30 20 150 300 200 100
// 10 20 30 100 150 200 300
// INS 12
// END	
// 12

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    int val;
    struct tree *left;
    struct tree *right;
} tree;

tree* create(int t) {
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->val = t;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

tree* insert(tree *start, int t) {
    tree *x = start;
    tree *p = NULL;

    // หาตำแหน่งที่จะแทรกโหนดใหม่
    while (x != NULL) {
        p = x;
        if (t < x->val)
            x = x->left;
        else if (t > x->val)
            x = x->right;
        else 
            return start;
    }

    
    tree *newnode = create(t);
    if (p == NULL) {
        // กรณีต้นไม้ว่าง
        start = newnode;
    } else if (t < p->val) {
        p->left = newnode;
    } else {
        p->right = newnode;
    }
    return start;
}

void preorder(tree *start) {
    if (start == NULL) return;

    tree *data[1000];
    int n = -1;
    data[++n] = start;

    while (n >= 0) {
        tree *x = data[n--];
        printf("%d ", x->val);

        if (x->right != NULL)
            data[++n] = x->right;
        if (x->left != NULL)
            data[++n] = x->left;
    }
    printf("\n");
}

void inorder(tree *start) {
    if (start == NULL) return;

    tree *data[1000];
    int n1 = -1;
    tree *x = start;

    while (x != NULL || n1 >= 0) {
        while (x != NULL) {
            data[++n1] = x;
            x = x->left;
        }
        x = data[n1--];
        printf("%d ", x->val);
        x = x->right;
    }
    printf("\n");
}

void postorder(tree *start) {
    if (start == NULL) return;

    tree *data[1000];
    int n1 = -1, n2 = -1;
    data[++n1] = start;
    tree *output[1000];

    while (n1 >= 0) {
        tree *x = data[n1--];
        output[++n2] = x;

        if (x->left != NULL)
            data[++n1] = x->left;
        if (x->right != NULL)
            data[++n1] = x->right;
    }

    while (n2 >= 0) {
        printf("%d ", output[n2--]->val);
    }
    printf("\n");
}

int main() {
    char input[100];
    tree *start = NULL;
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->left = NULL;
    newnode->right = NULL;

    while (1) {
        char ch[10];
        scanf("%s", ch);
        if (strcmp(ch, "INS") == 0) {
            int t;
            scanf("%d", &t);
            start = insert(start, t);
        } else if (strcmp(ch, "PREORDER") == 0) {
            preorder(start);
        } else if (strcmp(ch, "POSTORDER") == 0) {
            postorder(start);
        } else if (strcmp(ch, "INORDER") == 0) {
            inorder(start);
        } else if (strcmp(ch, "END") == 0) {
            inorder(start);
            break;
        }
    }
    return 0;
}
