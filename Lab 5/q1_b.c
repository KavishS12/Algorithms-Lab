#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct adjList {
    struct Node* head;
} adjList;

typedef struct Graph {
    struct adjList* arr;
    int vert;
} Graph;

Node* newNode(int data) {
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

Graph* createGraph(int v) {
    Graph* g = malloc(sizeof(Graph));
    g->vert = v;
    g->arr = (adjList*)malloc(v * sizeof(adjList));
    for (int i = 0; i < v; i++)
        g->arr[i].head = NULL;
    return g;
}

void add_edge(Graph* g, int src, int dest) {
    if (src >= g->vert || dest >= g->vert) {
        printf("Invalid source or destination vertex.\n");
        return;
    }

    Node* new = newNode(dest);
    new->next = NULL;

    if (g->arr[src].head == NULL) {
        g->arr[src].head = new;
    } else {
        Node* temp = g->arr[src].head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void sourceRemoval(Graph* g) {
    int* indegree = (int*)malloc(g->vert * sizeof(int));
    int i;

    for (i = 0; i < g->vert; i++)
        indegree[i] = 0;

    for (i = 0; i < g->vert; i++) {
        Node* temp = g->arr[i].head;
        while (temp != NULL) {
            indegree[temp->data]++;
            temp = temp->next;
        }
    }

    int* queue = (int*)malloc(g->vert * sizeof(int));
    int front = 0, rear = 0;

    for (i = 0; i < g->vert; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front != rear) {
        int u = queue[front++];

        printf("%d ", u);

        Node* temp = g->arr[u].head;
        while (temp != NULL) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0)
                queue[rear++] = temp->data;
            temp = temp->next;
        }
    }

    for (i = 0; i < g->vert; i++) {
        if (indegree[i] != 0) {
            printf("\nGraph contains a cycle.\n");
            break;
        }
    }

    free(indegree);
    free(queue);
}

int main() {
    int v, src, dest;
    Graph* g = NULL;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    g = createGraph(v);

    printf("Add edges: (-1,-1 to exit)\n");

    while (1) {
        printf("Enter the source vertex: ");
        scanf("%d", &src);
        printf("Enter the destination vertex: ");
        scanf("%d", &dest);
        if (src == -1 || dest == -1)
            break;
        add_edge(g, src, dest);
    }

    printf("Topological Sorting: ");
    sourceRemoval(g);
    printf("\n");

    return 0;
}
