#include <stdio.h>

// adj[][] = [[1,2], [0,2], [0,1,3,4], [2], [2]] 
int adj[5][5] = {
        {0,1,1,0,0},
        {1,0,1,0,0},
        {1,1,0,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
};

// int adj[5][5] = {
//     {0,1,1,0,0},  // Node 0 connected to 1 and 2
//     {1,0,0,1,0},  // Node 1 connected to 0 and 3
//     {1,0,0,0,1},  // Node 2 connected to 0 and 4
//     {0,1,0,0,0},  // Node 3 connected to 1
//     {0,0,1,0,0}   // Node 4 connected to 2
// };


int visited[5] = {0};


void dfs(int v, int vertices) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < vertices; i++) {
        if (visited[i] == 0 && adj[v][i] == 1) {
            dfs(i, vertices);
        }
    }
}

void main(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("DFS Traversal: \n");
    dfs(0, 5);

}