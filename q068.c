/*
Day 68: Topological Sort (Kahn's BFS Algorithm)

Problem: Implement topological sorting using in-degree array and queue (Kahn's Algorithm).

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Queue {
    int items[105];
    int front;
    int rear;
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

void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }

    return item;
}

void topologicalSort(int vertices, struct Node* adj[]) {
    int indegree[105] = {0};
    int topo[105];
    int topoCount = 0;
    struct Queue q;
    initializeQueue(&q);

    for (int i = 1; i <= vertices; i++) {
        struct Node* temp = adj[i];
        while (temp != NULL) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    for (int i = 1; i <= vertices; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        topo[topoCount++] = current;

        struct Node* temp = adj[current];
        while (temp != NULL) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0) {
                enqueue(&q, temp->vertex);
            }
            temp = temp->next;
        }
    }

    if (topoCount != vertices) {
        printf("Cycle detected. Topological sort is not possible.\n");
        return;
    }

    for (int i = 0; i < topoCount; i++) {
        printf("%d", topo[i]);
        if (i < topoCount - 1) {
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

    printf("Topological order using Kahn's Algorithm: ");
    topologicalSort(vertices, adj);

    return 0;
}
