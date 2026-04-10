/*
Day 69: Dijkstra's Algorithm (Shortest Path)

Problem: Given a weighted graph with non-negative edges, compute the shortest path
from a source vertex using a priority queue.

Input:
- Number of vertices
- Number of edges
- Source vertex
- Weighted edges (u, v, w)

Output:
- Shortest distance from source to each vertex
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct HeapNode arr[1000];
};

struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);

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

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent].dist <= heap->arr[index].dist) {
            break;
        }
        swap(&heap->arr[parent], &heap->arr[index]);
        index = parent;
    }
}

void heapifyDown(struct MinHeap* heap, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist) {
            smallest = left;
        }
        if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist) {
            smallest = right;
        }
        if (smallest == index) {
            break;
        }

        swap(&heap->arr[index], &heap->arr[smallest]);
        index = smallest;
    }
}

void push(struct MinHeap* heap, int vertex, int dist) {
    heap->arr[heap->size].vertex = vertex;
    heap->arr[heap->size].dist = dist;
    heapifyUp(heap, heap->size);
    heap->size++;
}

struct HeapNode pop(struct MinHeap* heap) {
    struct HeapNode root = heap->arr[0];
    heap->size--;
    heap->arr[0] = heap->arr[heap->size];
    heapifyDown(heap, 0);
    return root;
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

void dijkstra(int vertices, struct Node* adj[], int source) {
    int dist[105];
    struct MinHeap heap;
    heap.size = 0;

    for (int i = 1; i <= vertices; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;
    push(&heap, source, 0);

    while (!isEmpty(&heap)) {
        struct HeapNode current = pop(&heap);
        int u = current.vertex;
        int currentDist = current.dist;

        if (currentDist > dist[u]) {
            continue;
        }

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (int i = 1; i <= vertices; i++) {
        if (dist[i] == INF) {
            printf("Vertex %d -> INF\n", i);
        } else {
            printf("Vertex %d -> %d\n", i, dist[i]);
        }
    }
}

int main() {
    int vertices;
    int edges;
    int source;
    struct Node* adj[105] = {NULL};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("Enter %d weighted undirected edges (u v w):\n", edges);
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }

    dijkstra(vertices, adj, source);

    return 0;
}
