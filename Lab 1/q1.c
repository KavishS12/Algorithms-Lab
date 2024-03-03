#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* createNode(int x){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = x;
	new->right = NULL;
	new->left = NULL;
	return new;
}

struct node *insertBST(struct node *root, int x) {
    if(root == NULL) {
        return createNode(x);
    }
    if (x < root->data) {
        root->left = insertBST(root->left, x);
    }
    else if (x > root->data) {
        root->right = insertBST(root->right, x);
    }
    else if(x == root->data){
    	printf("Dublicate elements not allowed.\n");
    }
    return root;
}

struct node *searchBST(struct node *root,int key){
    if(root == NULL || root->data == key){
       return root;
    }
    if(key<root->data)
        return searchBST(root->left,key);
    else
        return searchBST(root->right,key);
}

void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
	int choice;
	struct node *tree;
	tree = NULL;

	do{
		printf("\nEnter 1.Insert ,2.Search ,3.Preorder ,4.Postorder ,5.Inorder ,-1.Exit:\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Enter element to insert:");
				int n;
				scanf("%d",&n);
				tree = insertBST(tree,n);
				break;
			case 2:
				printf("Enter key:");
				int key;
				scanf("%d",&key);
				struct node* temp = searchBST(tree,key);
				if(temp == NULL){
					tree = insertBST(tree,key);
					printf("Key not found.Inserted in BST.");
				}
				else{
					printf("key found");
				}
				break;
			case 3:
				preOrder(tree);
				break;
			case 4:
				postOrder(tree);
				break;
			case 5:
				inOrder(tree);
				break;
			default:
				choice = -1;
		}
	}while(choice != -1);

	return 0;
}