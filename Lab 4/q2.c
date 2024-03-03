#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct adjList {
    struct Node* head;
}adjList;

typedef struct Graph {
    struct adjList* arr;
    int vert;
}Graph;

Node* newNode(int data){
    Node* new=malloc(sizeof(Node));
    new->data=data;
    new->next=NULL;
    return new;
}

Graph* createGraph(int v){
    Graph* g=malloc(sizeof(Graph));
    g->vert=v;
    g->arr=(adjList*)malloc(v*sizeof(adjList));
    for(int i=0;i<v;i++)
        g->arr[i].head=NULL;
    return g;
}

void add_edge(Graph* g,int src,int dest) {
    if (src>=g->vert||dest>=g->vert) {
        printf("Invalid source or destination vertex.\n");
        return;
    }

    Node* new=newNode(dest);
    new->next=NULL;

    if (g->arr[src].head==NULL) {
        g->arr[src].head=new;
    } else {
        Node* temp=g->arr[src].head;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=new;
    }

    Node* newNode2 = newNode(src);
    newNode2->next = NULL;

    if (g->arr[dest].head == NULL) {
        g->arr[dest].head = newNode2;
    } else {
        Node* temp = g->arr[dest].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode2;
    }
}
void dfsUtil(Graph* g, int vertex, int* visited) {
    
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = g->arr[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            dfsUtil(g, adjVertex, visited);
        }
        temp=temp->next;
    }
}

void dfs(Graph* g,int vertex){
    int* visited=(int*)malloc(g->vert*sizeof(int));
    for(int i=0;i<g->vert;i++){
        visited[i]=0;
    }
    dfsUtil(g,vertex,visited);
    free(visited);
}

int main() {
    int choice, v, src, dest;
    Graph* g = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a graph\n");
        printf("2. Add an edge\n");
        printf("3. Perform DFS\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number of vertices: ");
            scanf("%d", &v);
            g = createGraph(v);
            printf("Graph created successfully!\n");
            break;
        case 2:
            if (g == NULL) {
                printf("Please create a graph first!\n");
                break;
            }
            printf("Enter the source vertex: ");
            scanf("%d", &src);
            printf("Enter the destination vertex: ");
            scanf("%d", &dest);
            add_edge(g, src, dest);
            printf("Edge added successfully!\n");
            break;
        case 3:
            if (g == NULL) {
                printf("Please create a graph first!\n");
                break;
            }
            printf("Enter the starting vertex for DFS: ");
            scanf("%d", &src);
            dfs(g, src);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

