#include <stdio.h>

#define E 5
#define V 6

int edges[][2] = {
    {0, 3},
    {0, 4},
    {1, 4},
    {1, 5},
    {2, 5}
};

int combinations[32][5] = {
    {-1,-1,-1,-1,-1},

    {0,-1,-1,-1,-1},
    {1,-1,-1,-1,-1},
    {2,-1,-1,-1,-1},
    {3,-1,-1,-1,-1},
    {4,-1,-1,-1,-1},

    {0,1,-1,-1,-1},
    {0,2,-1,-1,-1},
    {0,3,-1,-1,-1},
    {0,4,-1,-1,-1},
    {1,2,-1,-1,-1},
    {1,3,-1,-1,-1},
    {1,4,-1,-1,-1},
    {2,3,-1,-1,-1},
    {2,4,-1,-1,-1},
    {3,4,-1,-1,-1},

    {0,1,2,-1,-1},
    {0,1,3,-1,-1},
    {0,1,4,-1,-1},
    {0,2,3,-1,-1},
    {0,2,4,-1,-1},
    {0,3,4,-1,-1},
    {1,2,3,-1,-1},
    {1,2,4,-1,-1},
    {1,3,4,-1,-1},
    {2,3,4,-1,-1},

    {0,1,2,3,-1},
    {0,1,2,4,-1},
    {0,1,3,4,-1},
    {0,2,3,4,-1},
    {1,2,3,4,-1},

    {0,1,2,3,4}
};

int arr[32];
int p = 0;

void printMatching(int index)
{
    int j;

    printf("{ ");

    for(j = 0; j < E; j++)
    {
        if(combinations[index][j] != -1)
        {
            printf("%d ", combinations[index][j]);
        }
    }

    printf("}");
}

void findMatching()
{
    int i, j, k;
    int x, start, end;
    int flag;
    int freq[V];
    
    p = 0;
    printf("All Matchings:\n");

    //code for Find Matching
    for (int i = 0; i < 32; i++) {
        
        for (int v = 0; v < V; v++) {
            freq[v] = 0;
        }

        flag = 1; 

        for (int j = 0; j < E; j++) {
            int edgeIndex = combinations[i][j];

            if (edgeIndex != -1) {
                int u = edges[edgeIndex][0];
                int v = edges[edgeIndex][1];

                freq[u]++;
                freq[v]++;

                if (freq[u] > 1 || freq[v] > 1) {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag)
        {
            arr[p++] = i; // Save valid matching combination index
            printMatching(i);
            printf("\n");
        }
    }
    printf("\n");
}

void findMaximalMatching()
{
    int i, j, e;
    int index;
    int u, v;
    int edgeIndex;
    int start, end;
    int freq[V];
    int maximal;

    printf("Maximal Matchings:\n");
    //code for Find Maximal Matching

    for (int i = 0; i < p; i++) {
        index = arr[i];

        for (v = 0; v < V; v++) {
            freq[v] = 0;
        }

        for (j = 0; j < E; j++) {
            int edgeIndex = combinations[index][j];

            if (edgeIndex != -1) {
                freq[edges[edgeIndex][1]]++;
                freq[edges[edgeIndex][0]]++;
            }
        }

        maximal = 1;

        for (e = 0; e < E; e++) {
            int inMatching = 0;
            for (j = 0; j < E; j++) {
                if (combinations[index][j] == e) {
                    inMatching = 1;
                    break;
                }
            }

            if (!inMatching) {
                u = edges[e][0];
                v = edges[e][1];
                if (freq[u] == 0 && freq[v] == 0) {
                    maximal = 0;
                    break;
                }
            }
        }
        if (maximal)
        {
            printMatching(index);
            printf("\n");
        }
    }
    printf("\n");
}

void findMaximumMatching()
{
    int i, j;
    int index;
    int size;
    int maxSize = 0;
	
    printf("Maximum Matching:\n");
	//code for find Maximal Matching
	for (i = 0; i < p; i++)
    {
        index = arr[i];
        size = 0;
        for (j = 0; j < E; j++)
        {
            if (combinations[index][j] != -1)
            {
                size++;
            }
        }

        if (size > maxSize)
        {
            maxSize = size;
        }
    }

    for (i = 0; i < p; i++)
    {
        index = arr[i];
        size = 0;
        for (j = 0; j < E; j++)
        {
            if (combinations[index][j] != -1)
            {
                size++;
            }
        }

        if (size == maxSize)
        {
            printMatching(index);
            printf(" (Size: %d)\n", maxSize);
        }
    }
}

void main()
{
    findMatching();

    findMaximalMatching();

    findMaximumMatching();
}

// #include <stdio.h>

// #define E 5
// #define V 6

// int edges[][2] = {
//     {0, 3},
//     {0, 4},
//     {1, 4},
//     {1, 5},
//     {2, 5}
// };

// int combinations[32][5] = {
//     {-1,-1,-1,-1,-1},

//     {0,-1,-1,-1,-1},
//     {1,-1,-1,-1,-1},
//     {2,-1,-1,-1,-1},
//     {3,-1,-1,-1,-1},
//     {4,-1,-1,-1,-1},

//     {0,1,-1,-1,-1},
//     {0,2,-1,-1,-1},
//     {0,3,-1,-1,-1},
//     {0,4,-1,-1,-1},
//     {1,2,-1,-1,-1},
//     {1,3,-1,-1,-1},
//     {1,4,-1,-1,-1},
//     {2,3,-1,-1,-1},
//     {2,4,-1,-1,-1},
//     {3,4,-1,-1,-1},

//     {0,1,2,-1,-1},
//     {0,1,3,-1,-1},
//     {0,1,4,-1,-1},
//     {0,2,3,-1,-1},
//     {0,2,4,-1,-1},
//     {0,3,4,-1,-1},
//     {1,2,3,-1,-1},
//     {1,2,4,-1,-1},
//     {1,3,4,-1,-1},
//     {2,3,4,-1,-1},

//     {0,1,2,3,-1},
//     {0,1,2,4,-1},
//     {0,1,3,4,-1},
//     {0,2,3,4,-1},
//     {1,2,3,4,-1},

//     {0,1,2,3,4}
// };

// int arr[32]; // Stores indices of valid matchings in combinations array
// int p = 0;   // Count of valid matchings found

// void printMatching(int index)
// {
//     int j;

//     printf("{ ");

//     for(j = 0; j < E; j++)
//     {
//         if(combinations[index][j] != -1)
//         {
//             printf("%d ", combinations[index][j]);
//         }
//     }

//     printf("}");
// }

// void findMatching()
// {
//     int i, j, k;
//     int edgeIndex;
//     int u, v;
//     int flag;
//     int freq[V];

//     p = 0;
//     printf("All Matchings:\n");

//     for (i = 0; i < 32; i++)
//     {
//         // Reset vertex frequency tracker
//         for (v = 0; v < V; v++)
//         {
//             freq[v] = 0;
//         }

//         flag = 1; // Assume combination is a valid matching

//         for (j = 0; j < E; j++)
//         {
//             edgeIndex = combinations[i][j];
//             if (edgeIndex != -1)
//             {
//                 u = edges[edgeIndex][0];
//                 v = edges[edgeIndex][1];

//                 freq[u]++;
//                 freq[v]++;

//                 // If any vertex is used more than once, it's not a valid matching
//                 if (freq[u] > 1 || freq[v] > 1)
//                 {
//                     flag = 0;
//                     break;
//                 }
//             }
//         }

//         if (flag)
//         {
//             arr[p++] = i; // Save valid matching combination index
//             printMatching(i);
//             printf("\n");
//         }
//     }
//     printf("\n");
// }

// void findMaximalMatching()
// {
//     int i, j, e;
//     int index;
//     int edgeIndex;
//     int u, v;
//     int freq[V];
//     int maximal;

//     printf("Maximal Matchings:\n");

//     // Check each valid matching stored in arr[]
//     for (i = 0; i < p; i++)
//     {
//         index = arr[i];

//         // Track vertices used in current matching
//         for (v = 0; v < V; v++)
//         {
//             freq[v] = 0;
//         }

//         for (j = 0; j < E; j++)
//         {
//             edgeIndex = combinations[index][j];
//             if (edgeIndex != -1)
//             {
//                 freq[edges[edgeIndex][0]]++;
//                 freq[edges[edgeIndex][1]]++;
//             }
//         }

//         maximal = 1;

//         // Check if any unused edge can be safely added
//         for (e = 0; e < E; e++)
//         {
//             // Check if edge 'e' is not already in the matching
//             int inMatching = 0;
//             for (j = 0; j < E; j++)
//             {
//                 if (combinations[index][j] == e)
//                 {
//                     inMatching = 1;
//                     break;
//                 }
//             }

//             // If edge is not in matching, check if its endpoints are free
//             if (!inMatching)
//             {
//                 u = edges[e][0];
//                 v = edges[e][1];
//                 if (freq[u] == 0 && freq[v] == 0)
//                 {
//                     maximal = 0; // Edge 'e' could be added, so this matching isn't maximal
//                     break;
//                 }
//             }
//         }

//         if (maximal)
//         {
//             printMatching(index);
//             printf("\n");
//         }
//     }
//     printf("\n");
// }

// void findMaximumMatching()
// {
//     int i, j;
//     int index;
//     int size;
//     int maxSize = 0;

//     printf("Maximum Matching(s):\n");

//     // First pass: Find maximum cardinality among valid matchings
//     for (i = 0; i < p; i++)
//     {
//         index = arr[i];
//         size = 0;
//         for (j = 0; j < E; j++)
//         {
//             if (combinations[index][j] != -1)
//             {
//                 size++;
//             }
//         }

//         if (size > maxSize)
//         {
//             maxSize = size;
//         }
//     }

//     // Second pass: Print all matchings that match the maximum size
//     for (i = 0; i < p; i++)
//     {
//         index = arr[i];
//         size = 0;
//         for (j = 0; j < E; j++)
//         {
//             if (combinations[index][j] != -1)
//             {
//                 size++;
//             }
//         }

//         if (size == maxSize)
//         {
//             printMatching(index);
//             printf(" (Size: %d)\n", maxSize);
//         }
//     }
//     printf("\n");
// }

// void main()
// {
//     findMatching();
//     findMaximalMatching();
//     findMaximumMatching();
// }