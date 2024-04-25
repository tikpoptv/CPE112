//66070503448 Phattharapong Duangkham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    int val;
    struct tree *left,*right;
}tree;

tree* create(int t) {
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode->val = t;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

tree* insert(tree *start,int t) {
    if(start == NULL) {
        return create(t);
    }
    if(t < start->val) {
        start->left = insert(start->left,t);
    }
    else if(t > start->val) {
        start->right = insert(start->right,t);
    }
    return start;
}

void preorder(tree *start) {
    if(start != NULL) {
        printf("%d ",start->val);
        preorder(start->left);
        preorder(start->right);
    }
}

void inorder(tree *start) {
    if(start != NULL) {
        inorder(start->left);
        printf("%d ",start->val);
        inorder(start->right);
    }
}

void postorder(tree *start) {
    if(start != NULL) {
        postorder(start->left);
        postorder(start->right);
        printf("%d ",start->val);
    }
}

int main() {
    tree *start = NULL;
    while (1) {
        char ch[10]; scanf("%s",ch);
        if(strcmp(ch,"INS")==0) {
            if(start == NULL) {
                int t; scanf("%d",&t);
                start = create(t);
                continue;
            }
            int t; scanf("%d",&t);
            insert(start,t);
        }
        else if(strcmp(ch,"PREORDER")==0) {
            preorder(start);
            printf("\n");
        }
        else if(strcmp(ch,"POSTORDER")==0) {
            postorder(start);
            printf("\n");
        }
        else if(strcmp(ch,"INORDER")==0) {
            inorder(start);
            printf("\n");
        }
        else if(strcmp(ch,"END")==0) {
            break;
        }
    }
    inorder(start);
    printf("\n");
}