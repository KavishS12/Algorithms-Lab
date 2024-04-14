#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void warshall(int **p, int n) {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
}

int main() {
    int n, e, u, v, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    int **p = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        p[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
            p[i][j] = 0; // Initialize all elements to 0
    }

    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++) {
        printf("Enter the end vertices of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        p[u][v] = 1;
    }

    printf("\nMatrix of input data:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    warshall(p, n);

    printf("\nTransitive closure:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", p[i][j]);
        printf("\n");
    }

    return 0;
}