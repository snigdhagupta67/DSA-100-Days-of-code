#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node, weight;
} Edge;

Edge adj[MAX][MAX];
int adjSize[MAX];

int dist[MAX];
int visited[MAX];

void dijkstra(int n, int source) {
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;

        // Find minimum distance node
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Relax neighbors
        for(int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].node;
            int w = adj[u][i].weight;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        adjSize[i] = 0;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]].node = v;
        adj[u][adjSize[u]].weight = w;
        adjSize[u]++;
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}