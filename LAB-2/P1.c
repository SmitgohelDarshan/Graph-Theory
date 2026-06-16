#include <stdio.h>

void main(){
    // adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]] 
    int adj[5][5] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    int visited[5] = {0};
    int queue[5];

    visited[0] = 1;
    int f = 0, r = 0;
    queue[r] = 0;

    printf("BFS Traversal: \n");
    while (f <= r) {
        int current = queue[f++];
        printf("%d ", current);

        for (int i = 0; i < 5; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++r] = i;
            }
        }
    }
}