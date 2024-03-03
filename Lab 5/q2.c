#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* createNode(int x) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->left = new->right = NULL;
    return new;
}

struct node* createBinaryTree()
{
    struct node *p;
    int n;
    printf("Enter data(-1 for no data):");
    scanf("%d",&n);

    if(n == -1) return NULL;

    p = (struct node*)malloc(sizeof(struct node));
    p->data=n;

    printf("Enter left child of %d:\n",n);
    p->left=createBinaryTree();

    printf("Enter right child of %d:\n",n);
    p->right=createBinaryTree();
    return p;
}

struct node* findCCA(struct node* root, int n1, int n2) {
    if (root == NULL){
        return NULL;
    }
 
    if (root->data == n1 || root->data == n2){
        return root;
    }
 
    struct node* leftCCA = findCCA(root->left, n1, n2);
    struct node* rightCCA = findCCA(root->right, n1, n2);
 
    if (leftCCA && rightCCA){
        return root;
    }
 
    if(leftCCA != NULL){
        return leftCCA;
    }
    else return rightCCA;
}
 
int main() {
    struct node* root = createBinaryTree();
    int n1, n2;

    printf("Enter the value of node 1: ");
    scanf("%d", &n1);
    printf("Enter the value of node 2: ");
    scanf("%d", &n2);
 
    struct node* cca = findCCA(root, n1, n2);
 
    if (cca != NULL)
        printf("Closest Common Ancestor of %d and %d is %d\n", n1, n2, cca->data);
    else
        printf("No Common Ancestor found for %d and %d\n", n1, n2);
 
    return 0;
}