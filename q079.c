/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
First line contains number of vertices and edges.
Next m lines contain edges in the form u v w.
Last line contains the source vertex.

Output Format
Print shortest distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via Dijkstra's algorithm.
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
        if (u >= 1 && u <= n && v >= 1 && v <= n && w >= 0)
        {
            if (w < graph[u][v])
            {
                graph[u][v] = w;
            }
        }
    }

    int source;
    printf("Enter source vertex: ");
    if (scanf("%d", &source) != 1 || source < 1 || source > n)
    {
        for (int i = 0; i <= n; i++)
        {
            free(graph[i]);
        }
        free(graph);
        return 0;
    }

    int *dist = (int *)malloc((size_t)(n + 1) * sizeof(int));
    int *visited = (int *)calloc((size_t)(n + 1), sizeof(int));
    if (dist == NULL || visited == NULL)
    {
        printf("Memory allocation failed.\n");
        free(dist);
        free(visited);
        for (int i = 0; i <= n; i++)
        {
            free(graph[i]);
        }
        free(graph);
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int count = 1; count <= n; count++)
    {
        int u = -1;
        int minDist = INF;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
        {
            break;
        }

        visited[u] = 1;

        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from source %d: ", source);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            printf("INF");
        }
        else
        {
            printf("%d", dist[i]);
        }

        if (i < n)
        {
            printf(" ");
        }
    }
    printf("\n");

    free(dist);
    free(visited);
    for (int i = 0; i <= n; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
