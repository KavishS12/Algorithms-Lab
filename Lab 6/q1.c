#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

struct node{
	int data;
	struct node *left,*right;
};

struct node *createNode(int x){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = x;
	new->left = NULL;
	new->right = NULL;
	return new;
}

struct node *createBT(){
	int n;
	printf("Enter data(-1 for no data):");
	scanf("%d",&n);
	if(n==-1)return NULL;
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->data = n;
	printf("Enter left root of %d\n",n);
	root->left = createBT();
	printf("Enter right root of %d\n",n);
	root->right = createBT();
	return root;
}

int totalNodes(struct node *root){
	opcount++;
	if(root == NULL){
		return 0;
	}
	return 1+totalNodes(root->left)+totalNodes(root->right);
}

int main()
{
	struct node *root = createBT();
	int res = totalNodes(root);
	printf("Total number of nodes = %d\n",res);
	printf("Opcount = %d",opcount);
	return 0;
}