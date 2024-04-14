#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int **table, int n, int *weights, int *profits) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if ((j - weights[i - 1]) < 0) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = max(table[i - 1][j], table[i - 1][j - weights[i - 1]] + profits[i - 1]);
            }
        }
    }
    int result = table[n][W];
    return result;
}

int main() {
    int W, n;
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    int *weights = (int *)malloc(n * sizeof(int));
    printf("Enter the weights of %d objects: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int *profits = (int *)malloc(n * sizeof(int));
    printf("Enter the profits of %d objects: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    int **table = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        table[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (int j = 0; j <= W; j++) {
        table[0][j] = 0;
    }
    for (int i = 0; i <= n; i++) {
        table[i][0] = 0;
    }

    int answer = knapsack(W, table, n, weights, profits);
    printf("Answer: %d\n", answer);
    
    return 0;
}