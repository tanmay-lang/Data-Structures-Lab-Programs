#include <stdio.h>

void dfs(int);
int n, i, j, a[10][10], vis[10];

int main() {
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }

    printf("DFS Traversal:\n");
    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }

    return 0;
}

void dfs(int v) {
    vis[v] = 1;
    printf("%d ", v);

    for (j = 0; j < n; j++) {
        if (a[v][j] == 1 && vis[j] == 0) {
            dfs(j);
        }
    }
}
