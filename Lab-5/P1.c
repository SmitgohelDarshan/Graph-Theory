#include <stdio.h>

int adj[4][4] = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
};

int visited[4] = {0};
int counts = 0;

void dfs(int v, int vertices) {
    visited[v] = 1;
    // printf("%d ", v);

    for (int i = 0; i < vertices; i++) {
        if (visited[i] == 0 && adj[v][i] == 1) {
            dfs(i, vertices);
        }
    }
}

void main(){

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    // printf("DFS Traversal: \n");
    
    for (int i = 0; i < 4; i++) {
        if (visited[i] == 0) {
            dfs(i, 4);
            counts++;
        }
    }
    
    printf("Friends Circle Counts: %d",counts);
}