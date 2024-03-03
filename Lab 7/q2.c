#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}Node; 

int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int maxOf(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

Node* newNode(int key) 
{ 
	Node* node = (Node*) malloc(sizeof(Node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; 
	return(node); 
} 

Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	y->height = maxOf(height(y->left), height(y->right)) + 1; 
	x->height = maxOf(height(x->left), height(x->right)) + 1; 

	return x; 
} 

Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = maxOf(height(x->left), height(x->right)) + 1; 
	y->height = maxOf(height(y->left), height(y->right)) + 1; 

	return y; 
} 

int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

Node* insert(Node* node, int key) 
{ 
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else 
		return node; 

	node->height = 1 + maxOf(height(node->left), height(node->right)); 

	int balance = getBalance(node); 

	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	return node; 
} 

void preOrder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		printf("%d ", root->key); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

Node* minValueNode(Node* node) 
{ 
	Node* current = node; 

	while (current->left != NULL) 
		current = current->left; 

	return current; 
} 

Node* search(Node* root, int key) 
{ 
	if (root == NULL || root->key == key) 
		return root; 

	if (root->key < key) 
		return search(root->right, key); 

	return search(root->left, key); 
} 

Node* findSuccessor(Node* root, int key) 
{ 
	Node* current = search(root, key); 

	if (current == NULL) 
		return NULL; 

	if (current->right != NULL) 
		return minValueNode(current->right); 

	Node* successor = NULL; 

	while (root != NULL) 
	{ 
		if (current->key < root->key) 
		{ 
			successor = root; 
			root = root->left; 
		} 
		else if (current->key > root->key) 
			root = root->right; 
		else
			break; 
	} 

	return successor; 
} 

Node* findPredecessor(Node* root, int key) 
{ 
	Node* current = search(root, key); 

	if (current == NULL) 
		return NULL; 

	if (current->left != NULL) 
	{ 
		Node* temp = current->left; 
		while (temp->right) 
			temp = temp->right; 
		return temp; 
	} 

	Node* predecessor = NULL; 

	while (root != NULL) 
	{ 
		if (current->key > root->key) 
		{ 
			predecessor = root; 
			root = root->right; 
		} 
		else if (current->key < root->key) 
			root = root->left; 
		else
			break; 
	} 

	return predecessor; 
} 

int main() 
{ 
	Node *root = NULL; 
	int choice, key;

	do {
		printf("\nMenu:\n");
		printf("1. Insert a key\n");
		printf("2. Find successor\n");
		printf("3. Find predecessor\n");
		printf("4. Preorder traversal\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter the key to insert: ");
				scanf("%d", &key);
				root = insert(root, key);
				break;
			case 2:
				printf("Enter the key to find successor: ");
				scanf("%d", &key);
				Node* successor = findSuccessor(root, key);
				if (successor != NULL)
					printf("Successor of %d is %d\n", key, successor->key);
				else
					printf("No successor found for %d\n", key);
				break;
			case 3:
				printf("Enter the key to find predecessor: ");
				scanf("%d", &key);
				Node* predecessor = findPredecessor(root, key);
				if (predecessor != NULL)
					printf("Predecessor of %d is %d\n", key, predecessor->key);
				else
					printf("No predecessor found for %d\n", key);
				break;
			case 4:
				printf("Preorder traversal of the AVL tree is: ");
				preOrder(root);
				printf("\n");
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 5);

	return 0; 
}
