/*
Day 70: Bellman-Ford Algorithm

Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- Number of vertices
- Number of directed edges
- Source vertex
- Directed weighted edges (u, v, w)

Output:
- Shortest distances or NEGATIVE CYCLE
*/

#include <stdio.h>

#define INF 100000000

struct Edge {
    int u;
    int v;
    int w;
};

void bellmanFord(int vertices, int edges, struct Edge edgeList[], int source) {
    int dist[105];

    for (int i = 1; i <= vertices; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edgeList[j].u;
            int v = edgeList[j].v;
            int w = edgeList[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < edges; j++) {
        int u = edgeList[j].u;
        int v = edgeList[j].v;
        int w = edgeList[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
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
    struct Edge edgeList[205];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of directed edges: ");
    scanf("%d", &edges);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("Enter %d directed weighted edges (u v w):\n", edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &edgeList[i].u, &edgeList[i].v, &edgeList[i].w);
    }

    bellmanFord(vertices, edges, edgeList, source);

    return 0;
}
