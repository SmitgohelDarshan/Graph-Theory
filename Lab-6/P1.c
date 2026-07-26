#include <stdio.h>
#define v 6
#define e 5
void dfs(int del, int adjMat[][v], int isVisited[], int node)
{
    isVisited[node] = 1;

    for (int i = 0; i < v; i++)
    {
        if (i == del)
            continue;
        if (adjMat[node][i] != 0 && isVisited[i] == 0)
        {
            dfs(del, adjMat, isVisited, i);
        }
    }
}

int dfs2(int del, int adjMat[][v], int isVisited[], int node, int count)
{
    isVisited[node] = 1;
    // printf("%d ", node);
    for (int i = 0; i < v; i++)
    {

        if (i != del && adjMat[node][i] != 0 && isVisited[i] == 0)
        {
            count += 1;
            dfs2(del, adjMat, isVisited, i, count);
        }
    }
    return count;
}

void main()
{
    // int v = 6,e = 5;
    int adjMat[v][v] = {{0, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0}};

    for (int i = 1; i < v; i++)
    {
        int isVisited[v] = {0};
        if (i == v - 1)
        {
            dfs(i, adjMat, isVisited, 0);
        }
        else
        {

            dfs(i - 1, adjMat, isVisited, i);
        }
        int flag = 1;
        for (int j = 0; j < v; j++)
        {
            if (i - 1 == j)
                continue;
            if (isVisited[j] != 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%d ", i);
    }

    printf("\n");

    // for (int i = 1; i <= v; i++)
    // {
    //     int isVisited[v] = {0};
    //     int count = 1;
    //     if (i == v)
    //     {
    //         count = dfs2(i - 1, adjMat, isVisited, 0, count);
    //         if (count != v - 1)
    //             printf("%d %d\n", i - 1, count);
    //     }
    //     else
    //     {

    //         count = dfs2(i - 1, adjMat, isVisited, i, count);
    //         if (count != v - 1)
    //             printf("%d %d\n", i - 1, count);
    //     }

    //     // int flag = 1;
    //     // for (int j = 0; j < v; j++)
    //     // {
    //     //     if (i - 1 == j)
    //     //         continue;
    //     //     if (isVisited[j] != 1)
    //     //     {
    //     //         flag = 0;
    //     //         break;
    //     //     }
    //     // }
    // }
}