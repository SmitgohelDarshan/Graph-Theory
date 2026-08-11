#include <stdio.h>

#define v 4

int adj[v][v] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 0}, {0, 1, 0, 0}};
int singles[4][1] = {{0}, {1}, {2}, {3}};
int pairs[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
int triplet[4][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};
int quadric[1][4] = {{0, 1, 2, 3}};

int isDominated(int row, int col, int (*arr)[col])
{
    int temp = 1;
    // int *arr[col];
    // if (size == 1)
    //     arr = singles;
    // else if (size == 2)
    //     arr = pairs;
    // else if (size == 3)
    //     arr = triplet;
    // else
    //     arr = quadric;

    for (int i = 0; i < row; i++)
    {
        int dominated[v] = {0};

        for (int j = 0; j < col; j++)
        {
            dominated[arr[i][j]] = 1;

            for (int k = 0; k < v; k++)
            {
                if (adj[arr[i][j]][k])
                    dominated[k] = 1;
            }
        }

        int flag = 1;
        for (int i = 0; i < v; i++)
        {
            if (!dominated[i])
                flag = 0;
        }
        if (flag)
        {
            printf("{");
            for (int j = 0; j < col; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("}\n");
            temp = 1;
        }
    }

    return temp;
}

int isTotalDominated(int row, int col, int (*arr)[col])
{
    int temp = 0;
    // int *arr[col];
    // if (size == 1)
    //     arr = singles;
    // else if (size == 2)
    //     arr = pairs;
    // else if (size == 3)
    //     arr = triplet;
    // else
    //     arr = quadric;

    for (int i = 0; i < row; i++)
    {
        int dominated[v] = {0};

        for (int j = 0; j < col; j++)
        {
            // dominated[arr[i][j]] = 1; NOT INCLUDED IN TOTAL DOMINATION

            for (int k = 0; k < v; k++)
            {
                if (adj[arr[i][j]][k])
                    dominated[k] = 1;
            }
        }

        int flag = 1;
        for (int i = 0; i < v; i++)
        {
            if (!dominated[i])
                flag = 0;
        }
        if (flag)
        {
            printf("{");
            for (int j = 0; j < col; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("}\n");
            temp = 1;
        }
    }

    return temp;
}

void main()
{
    int dominationNum = v + 1;
    int num = isDominated(4, 1, singles);
    if (num && dominationNum > 1)
        dominationNum = 1;
    // printf(" \n%d \n", dominationNum);
    num = isDominated(6, 2, pairs);
    if (num && dominationNum > 2)
        dominationNum = 2;
    // printf(" \n%d \n", dominationNum);
    num = isDominated(4, 3, triplet);
    if (num && dominationNum > 3)
        dominationNum = 3;
    // printf(" \n%d \n", dominationNum);
    num = isDominated(1, 4, quadric);
    if (num && dominationNum > 4)
        dominationNum = 4;
    printf("dominationNum = %d \n\n", dominationNum);

    int totalDominationNum = v + 1;
    int num2 = isTotalDominated(4, 1, singles);
    if (num2 && totalDominationNum > 1)
        totalDominationNum = 1;
    // printf(" \n%d \n", dominationNum);
    num2 = isTotalDominated(6, 2, pairs);
    // printf("num2 = %d", num2);
    if (num2 && totalDominationNum > 2)
        totalDominationNum = 2;
    // printf(" \n%d \n", totalDominationNum);
    num2 = isTotalDominated(4, 3, triplet);
    if (num2 && totalDominationNum > 3)
        totalDominationNum = 3;
    // printf(" \n%d \n", totalDominationNum);
    num2 = isTotalDominated(1, 4, quadric);
    if (num2 && totalDominationNum > 4)
        totalDominationNum = 4;
    printf("totalDominationNum = %d \n", totalDominationNum);
}