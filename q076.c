/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
First line contains number of vertices and edges.
Next m lines contain edges of the undirected graph.

Output Format
Print the number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

static struct Node *addNode(struct Node *head, int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return head;
    }

    newNode->vertex = vertex;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

static void dfs(int node, struct Node *adj[], int visited[])
{
    visited[node] = 1;

    struct Node *temp = adj[node];
    while (temp != NULL)
    {
        if (!visited[temp->vertex])
        {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

static void freeGraph(struct Node *adj[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        struct Node *temp = adj[i];
        while (temp != NULL)
        {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

int main(void)
{
    int n, m;

    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m < 0)
    {
        printf("0\n");
        return 0;
    }

    struct Node **adj = (struct Node **)calloc((size_t)(n + 1), sizeof(struct Node *));
    int *visited = (int *)calloc((size_t)(n + 1), sizeof(int));

    if (adj == NULL || visited == NULL)
    {
        printf("Memory allocation failed.\n");
        free(adj);
        free(visited);
        return 1;
    }

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u >= 1 && u <= n && v >= 1 && v <= n)
        {
            adj[u] = addNode(adj[u], v);
            adj[v] = addNode(adj[v], u);
        }
    }

    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
            components++;
        }
    }

    printf("Number of connected components: %d\n", components);

    freeGraph(adj, n);
    free(adj);
    free(visited);
    return 0;
}
