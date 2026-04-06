/*
Day 65: Cycle Detection in Undirected Graph (DFS)

Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Input:
- Number of vertices
- Number of edges
- Undirected edges (u, v)

Output:
- YES or NO
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

int dfsHasCycle(int node, int parent, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfsHasCycle(neighbor, node, adj, visited)) {
                return 1;
            }
        } else if (neighbor != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int hasCycle(int vertices, struct Node* adj[]) {
    int visited[105] = {0};

    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) {
            if (dfsHasCycle(i, -1, adj, visited)) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int vertices;
    int edges;
    struct Node* adj[105] = {NULL};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d undirected edges (u v):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    if (hasCycle(vertices, adj)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
