/*
Day 66: Cycle Detection in Directed Graph

Problem: Detect cycle in directed graph using DFS and recursion stack.

Input:
- Number of vertices
- Number of directed edges
- Directed edges (u, v)

Output:
- YES if cycle exists, otherwise NO
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

int dfsCheck(int node, struct Node* adj[], int visited[], int pathVisited[]) {
    visited[node] = 1;
    pathVisited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfsCheck(neighbor, adj, visited, pathVisited)) {
                return 1;
            }
        } else if (pathVisited[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    pathVisited[node] = 0;
    return 0;
}

int hasCycle(int vertices, struct Node* adj[]) {
    int visited[105] = {0};
    int pathVisited[105] = {0};

    for (int i = 1; i <= vertices; i++) {
        if (!visited[i]) {
            if (dfsCheck(i, adj, visited, pathVisited)) {
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

    printf("Enter number of directed edges: ");
    scanf("%d", &edges);

    printf("Enter %d directed edges (u v):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (hasCycle(vertices, adj)) {
        printf(" adj vertices\n");
    } else {
        printf("NO adj vertices\n");
    }

    return 0;
}
