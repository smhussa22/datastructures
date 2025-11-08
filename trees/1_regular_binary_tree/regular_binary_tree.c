#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *left;
    struct Node *right;

};

struct Node* createNode(int data);
void insertLeft(struct Node* parent, int data);
void insertRight(struct Node* parent, int data);
void deleteTree(struct Node* root);
void preorderTraversal(struct Node* root);
void inorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);

int main() {

    struct Node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertRight(root->right, 6);
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    deleteTree(root);

    return 0;

}

struct Node* createNode(int data){

    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        
        fprintf(stderr, "newNode malloc failed @ createNode");
        exit(1);

    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

void insertLeft(struct Node* parent, int data){

    if(parent == NULL) return;
    if(parent->left != NULL){

        printf("Left child is already occupied.");
        return;

    }

    parent->left = createNode(data);
    return;    

}

void insertRight(struct Node* parent, int data){

    if(parent == NULL) return;
    if(parent->right != NULL){

        printf("Right child is already occupied.");
        return;

    }

    parent->right = createNode(data);
    return;

}

void deleteTree(struct Node* root){ // delete node along w/ subtree

    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);

}

void preorderTraversal(struct Node* root){

    if (root == NULL) return;
    printf("%d", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}

void inorderTraversal(struct Node* root){

    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d", root->data);
    inorderTraversal(root->right);

}

void postorderTraversal(struct Node* root){

    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d", root->data);

}
