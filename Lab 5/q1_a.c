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

typedef struct Stack{
    int st[20];
    int top;
}Stack;

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
}

void topologicalSortUtil_dfs(Graph* g, int vertex, int* visited,Stack *s) {
    visited[vertex] = 1;
    Node* temp = g->arr[vertex].head;

    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            topologicalSortUtil_dfs(g, adjVertex, visited,s);
        }
        temp=temp->next;
    }
    s->st[++(s->top)] = vertex;
}

void topologicalSort_dfs(Graph* g){
    int* visited=(int*)malloc(g->vert*sizeof(int));
    for(int i=0;i<g->vert;i++){
        visited[i]=0;
    }
    Stack *s;
    s->top = -1;
    for (int i = 0; i <g->vert; i++){
        if (visited[i] == 0){
            topologicalSortUtil_dfs(g,i,visited,s);
        }
    }
 
    while (s->top != -1 ){
        printf("%d ",s->st[s->top]);
        (s->top)--;
    }
    printf("\n");
    free(visited);
}

int main() {
    int choice, v, src, dest;
    Graph* g = NULL;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    g = createGraph(v);

    printf("Add edges:(-1,-1 to exit)");

    while (1) {
        printf("\nEnter the source vertex: ");
        scanf("%d", &src);
        printf("Enter the destination vertex: ");
        scanf("%d", &dest);
        if(src == -1 || dest == -1)break;
        add_edge(g, src, dest);
    }
    
    topologicalSort_dfs(g);
    return 0;
}