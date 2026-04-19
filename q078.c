/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim's algorithm.

Input Format
First line contains number of vertices and edges.
Next m lines contain edges in the form u v w.

Output Format
Print the total weight of the Minimum Spanning Tree.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main(void)
{
    int n, m;

    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m < 0)
    {
        printf("0\n");
        return 0;
    }

    int **graph = (int **)malloc((size_t)(n + 1) * sizeof(int *));
    if (graph == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i <= n; i++)
    {
        graph[i] = (int *)malloc((size_t)(n + 1) * sizeof(int));
        if (graph[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(graph[j]);
            }
            free(graph);
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = INF;
            }
        }
    }

    printf("Enter %d weighted edges (u v w):\n", m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u >= 1 && u <= n && v >= 1 && v <= n && w < graph[u][v])
        {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int *selected = (int *)calloc((size_t)(n + 1), sizeof(int));
    if (selected == NULL)
    {
        printf("Memory allocation failed.\n");
        for (int i = 0; i <= n; i++)
        {
            free(graph[i]);
        }
        free(graph);
        return 1;
    }

    selected[1] = 1;
    int totalWeight = 0;
    int edgesUsed = 0;

    while (edgesUsed < n - 1)
    {
        int minWeight = INF;
        int nextVertex = -1;

        for (int i = 1; i <= n; i++)
        {
            if (selected[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!selected[j] && graph[i][j] < minWeight)
                    {
                        minWeight = graph[i][j];
                        nextVertex = j;
                    }
                }
            }
        }

        if (nextVertex == -1)
        {
            printf("Graph is not connected. MST cannot be formed.\n");
            free(selected);
            for (int i = 0; i <= n; i++)
            {
                free(graph[i]);
            }
            free(graph);
            return 0;
        }

        selected[nextVertex] = 1;
        totalWeight += minWeight;
        edgesUsed++;
    }

    printf("Total weight of MST: %d\n", totalWeight);

    free(selected);
    for (int i = 0; i <= n; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
