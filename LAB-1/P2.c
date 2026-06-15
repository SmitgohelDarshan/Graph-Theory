#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void displayAdjMatrix(int vertices, int adj[MAX][MAX]) {
    printf("\nAdjacency Matrix\n");

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void displayAdjList(int vertices, int adj[MAX][MAX]) {
    printf("\nAdjacency List\n");

    for (int i = 0; i < vertices; i++) {
        printf("%d -> ", i);

        for (int j = 0; j < vertices; j++) {
            if (adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void findDegree(int vertices, int adj[MAX][MAX]) {
    printf("\nDegree of Each Vertex\n");

    for (int i = 0; i < vertices; i++) {
        int degree = 0;

        for (int j = 0; j < vertices; j++) {
            degree += adj[i][j];
        }

        printf("Degree of Vertex %d = %d\n", i, degree);
    }
}

void dfs(int v, int vertices, int adj[MAX][MAX], int visited[]) {
    visited[v] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, vertices, adj, visited);
        }
    }
}

void checkGraphProperties(int vertices, int adj[MAX][MAX]) {
    printf("\nGraph Properties\n");

    bool simple = true;
    for (int i = 0; i < vertices; i++) {
        if (adj[i][i] == 1) {
            simple = false;
            break;
        }
    }

    printf(simple ? "Graph is Simple\n" : "Graph is NOT Simple\n");


    bool complete = true;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i != j && adj[i][j] == 0) {
                complete = false;
                break;
            }
        }
        if (!complete) break;
    }

    printf(complete ? "Graph is Complete\n" : "Graph is NOT Complete\n");

    int visited[MAX] = {0};

    dfs(0, vertices, adj, visited);

    bool connected = true;

    for (int i = 0; i < vertices; i++) {
        if (visited[i] == 0) {
            connected = false;
            break;
        }
    }

    printf(connected ? "Graph is Connected\n" : "Graph is NOT Connected\n");
}

void displayTotalVerticesEdges(int vertices, int edges) {
    printf("Total Vertices = %d\n", vertices);
    printf("Total Edges = %d\n", edges);
}

void main() {
    int vertices, edges;

    printf("Enter Number of Vertices: ");
    scanf("%d", &vertices);

    printf("Enter Number of Edges: ");
    scanf("%d", &edges);

    int adj[MAX][MAX];

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    // Undirected
    for (int i = 0; i < edges; i++) {
        int u, v;

        printf("Enter Edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    displayAdjMatrix(vertices, adj);
    displayAdjList(vertices, adj);
    findDegree(vertices, adj);
    checkGraphProperties(vertices, adj);
    displayTotalVerticesEdges(vertices, edges);
}