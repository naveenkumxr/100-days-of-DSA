/*
Day 67: Topological Sort (DFS)

Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

Input:
- Number of vertices
- Number of directed edges
- Directed edges (u, v)

Output:
- Topological ordering of the graph
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);

    if (adj[u] == NULL) {
        adj[u] = newNode;
        return;
    }

    struct Node* temp = adj[u];
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void dfs(int node, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[(*top)++] = node;
}

void topologicalSort(int vertices, struct Node* adj[]) {
    int visited[105] = {0};
    int stack[105];
    int top = 0;

    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int vertices;
    int edges;
    struct Node* adj[105] = {NULL};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of directed edges: ");
    scanf("%d", &edges);

    printf("Enter %d directed edges (u v):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printf("Topological order: ");
    topologicalSort(vertices, adj);

    return 0;
}
