#include <stdio.h>
#include <stdlib.h>

#define INF 99999 

int max(int a, int b) {
    return (a > b) ? a : b;
}

void Floyd(int **p, int n) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
               { if (p[i][k] + p[k][j] < p[i][j])
                    p[i][j] = p[i][k] + p[k][j];}}

int main() {
    int n, e, u, v, w, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    int **p = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        p[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
        if(i==j)
        p[i][j]=0;
        else
            p[i][j] = INF; // Initialize all elements to infinity
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter the end vertices and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        p[u][v] = w; // Set the weight of the edge from vertex u to vertex v
    }

    printf("\nMatrix of input data:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (p[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    warshall(p, n);

    printf("\nAnswer :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (p[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}