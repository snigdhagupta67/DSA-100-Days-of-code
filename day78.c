#include <stdio.h>
#define MAX 100
#define INF 999999

int n, m;
int graph[MAX][MAX];

int prim() {
    int visited[MAX] = {0};
    int minEdge[MAX];
    int totalWeight = 0;

    // Initialize all edges as infinite
    for (int i = 1; i <= n; i++)
        minEdge[i] = INF;

    // Start from node 1
    minEdge[1] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        // Find minimum edge
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += minEdge[u];

        // Update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < minEdge[v]) {
                minEdge[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected
    }

    int result = prim();
    printf("%d\n", result);

    return 0;
}