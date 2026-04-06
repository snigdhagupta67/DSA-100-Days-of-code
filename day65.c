#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n;

// DFS function
bool dfs(int node, int parent)
{
    visited[node] = true;

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1)
        {
            if (!visited[i])
            {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent)
            {
                return true; // cycle found
            }
        }
    }
    return false;
}

int main()
{
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    // Check all components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}