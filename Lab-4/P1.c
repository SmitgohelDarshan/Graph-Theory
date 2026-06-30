//Input: V = 6, edges [][] = {(0,1), (1,2), (1,3), (3,4), (3,5)} 
#include <stdio.h>

int edges[5][2] = {{0,1}, {1,2}, {1,3}, {3,4}, {3,5}};
int V = 6; 

int adj[6][6] = {
    {0,1,0,0,0,0},
    {1,0,1,1,0,0},
    {0,1,0,0,0,0},
    {0,1,0,0,1,1},
    {0,0,0,1,0,0},
    {0,0,0,1,0,0}
};

int degreeArr[6] = {0}; 

int eccentricityArr[6] = {0};

void pendentVerticesAndDegreeOfEachVertex() {
    for (int i = 0; i < 5; i++) {
        degreeArr[edges[i][0]]++;
        degreeArr[edges[i][1]]++;
    }

    printf("Pendent Vertex: ");
    for (int i = 0; i < V; i++) {
        if (degreeArr[i] == 1) {
            printf("%d ", i);
        }
    }

    printf("\nDegree of each Vertex: \n");
    for (int i = 0; i < V; i++) {
        printf("Degree of %d: %d\n", i, degreeArr[i]);
    }
}

void bfs(int src) {
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = -1; // -1 means not visited
    }

    int queue[V], front = 0, rear = 0;
    dist[src] = 0;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    int max = 0;

    printf("Distances from vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> %d\n", i, dist[i]);
        max = (dist[i] > max) ? dist[i] : max;
    }

    printf("Eccentricity of Vertex %d = %d\n", src, max);
    eccentricityArr[src] = max;
}

void findDistanceBetweenVertices() {
    for (int i = 0; i < V; i++) {
        bfs(i);
    }
}

void findCenter() {
    int min = eccentricityArr[0];

    for (int i = 0; i < V; i++) {
        min = (eccentricityArr[i] < min) ? (eccentricityArr[i]) : min;
    }

    printf("Center of the Tree: ");
    for (int i = 0; i < V; i++) {
        if (eccentricityArr[i] == min) {
            printf("%d ", i);
        }
    }
}

void dfs(int v, int visited[]) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, visited);
        }
    }
}

void checkTree() {
    // int edgeCount = sizeof(edges) / sizeof(edges[0]);
    // if (edgeCount != V - 1)

    if (5 != V - 1) {
        printf("\nGraph is NOT a Tree");
        return;
    }

    int visited[6] = {0};

    dfs(0, visited);

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            printf("\nGraph is NOT a Tree");
            return;
        }
    }

    printf("\nGraph is a Tree");
}

void main(){
    pendentVerticesAndDegreeOfEachVertex();
    findDistanceBetweenVertices();
    findCenter();
    checkTree();
}