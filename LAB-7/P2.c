#include <stdio.h>

#define V 4
#define E 4

void dfs(int v, int visited[V], int adj[V][V]);
int isDisconnected(int adj[V][V]);

int adj[V][V] = {
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0}
};

int edges[E][2] = {
    {0,1},
    {0,2},
    {1,2},
    {1,3}
};

int combinations[16][E] = {
    {-1,-1,-1,-1},
    {3,-1,-1,-1},
    {2,-1,-1,-1},
    {2,3,-1,-1},
    {1,-1,-1,-1},
    {1,3,-1,-1},
    {1,2,-1,-1},
    {1,2,3,-1},
    {0,-1,-1,-1},
    {0,3,-1,-1},
    {0,2,-1,-1},
    {0,2,3,-1},
    {0,1,-1,-1},
    {0,1,3,-1},
    {0,1,2,-1},
    {0,1,2,3}
};

void dfs(int v, int visited[V], int adj[V][V])
{
    visited[v] = 1;
    for(int i = 0; i < V; i++)
    {
        if(adj[v][i] && !visited[i])
        {
            dfs(i, visited, adj);
        }
    }
}

int isDisconnected(int adj[V][V])
{
    int visited[V] = {0};

    dfs(0, visited, adj);

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            return 1;
    }

    return 0;
}

int main()
{
    for(int i = 0; i < 16; i++)
    {
        int temp[V][V];

        for(int r = 0; r < V; r++)
        {
            for(int c = 0; c < V; c++)
            {
                temp[r][c] = adj[r][c];
            }
        }

        for(int j = 0; j < E; j++)
        {
            if(combinations[i][j] == -1)
                break;

            int e = combinations[i][j];
            temp[edges[e][0]][edges[e][1]] = 0;
            temp[edges[e][1]][edges[e][0]] = 0;
        }

        if(isDisconnected(temp))
        {
            for(int j = 0; j < E; j++)
            {
                if(combinations[i][j] == -1)
                    break;

                int e = combinations[i][j];
                printf("(%d,%d)", edges[e][0], edges[e][1]);

                if(j < E - 1 && combinations[i][j + 1] != -1)
                    printf(", ");
            }
            printf("\n");
        }
    }

    return 0;
}