/*
Problem Statement
Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

Input Format
First line contains the number of vertices.
Next n lines contain the adjacency matrix of the graph.
Use -1 to indicate no direct edge between two vertices.

Output Format
Print the shortest distance matrix.

Sample Input
4
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0

Sample Output
0 5 8 9
-1 0 3 4
-1 -1 0 1
-1 -1 -1 0
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main(void)
{
    int n;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    int **dist = (int **)malloc((size_t)n * sizeof(int *));
    if (dist == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = (int *)malloc((size_t)n * sizeof(int));
        if (dist[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(dist[j]);
            }
            free(dist);
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    printf("Enter the %d x %d adjacency matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == -1 && i != j)
            {
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distance matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("-1");
            }
            else
            {
                printf("%d", dist[i][j]);
            }

            if (j < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(dist[i]);
    }
    free(dist);

    return 0;
}
