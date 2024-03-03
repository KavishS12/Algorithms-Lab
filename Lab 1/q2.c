#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node *next;
};

struct node* createNode(int x){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->vertex = x;
	new->next = NULL;
	return new;
}

struct Graph {
	int vertices;
	struct node** adjLists;
	int adjMatrix[10][10];
};

struct Graph* createGraph(int n) {
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->vertices = n;

	graph->adjLists = (struct node**)malloc(n * sizeof(struct node*));

	for (int i = 0; i < n; i++){
		graph->adjLists[i] = NULL;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			graph->adjMatrix[i][j] = 0;
		}
	}

	return graph;
}

void addEdge(struct Graph* graph, int u, int v) {

	struct node* temp = createNode(v);
	temp->next = graph->adjLists[u];
	graph->adjLists[u] = temp;

	temp = createNode(u);
	temp->next = graph->adjLists[v];
	graph->adjLists[v] = temp;

	graph->adjMatrix[u][v] = 1;
	graph->adjMatrix[v][u] = 1;

}

void printAdjList(struct Graph* graph) {
	for (int i = 0; i < graph->vertices; i++) {
		struct node* temp = graph->adjLists[i];
		printf("Vertex %d: ",i);
		while (temp->next!= NULL) {
		  printf("%d,", temp->vertex);
		  temp = temp->next;
		}
		printf("%d",temp->vertex);
		printf("\n");
	}
}

void printAdjMatrix(struct Graph* graph){
	for(int i=0;i<graph->vertices;i++){
		for(int j=0;j<graph->vertices;j++){
			printf("%d ",graph->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n;
	printf("enter the number of vertices:");
	scanf("%d",&n);

	struct Graph* graph = createGraph(n);
	int choice;
	do{
		printf("\nEnter 1.Add edge -1.Exit :");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the two vertices:");
				int u,v;
				scanf("%d%d",&u,&v);
				addEdge(graph,u,v);
				break;
			default:
				choice = -1;
		}
	}while(choice != -1);

	printf("\nAdjacency list : \n");
	printAdjList(graph);
	printf("\nAdjacency matrix : \n");
	printAdjMatrix(graph);

	return 0;
}

