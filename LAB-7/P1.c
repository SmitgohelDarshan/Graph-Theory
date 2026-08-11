#include <stdio.h>

#define V 6
#define E 7

int edges[E][2] = {
    {0,1},
    {0,2},
    {1,2},
    {1,3},
    {2,4},
    {3,4},
    {3,5}
};

int visited[V] = {0};

int branch[V-1][2];
int branchCount = 0;

int chord[E - (V - 1)][2];
int chordCount = 0;

int adjMatrix[V][V] = {0};

void dfsComponent(int v, int tempVisited[], int ignoreVertex, int ignoreEdge) {
    tempVisited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adjMatrix[v][i] == 1 && !tempVisited[i]) {
            // Skip the vertex we want to test removing
            if (i == ignoreVertex) continue;

            // Skip the edge we want to test removing
            if (ignoreEdge != -1) {
                int u1 = edges[ignoreEdge][0];
                int v1 = edges[ignoreEdge][1];
                if ((v == u1 && i == v1) || (v == v1 && i == u1)) continue;
            }

            dfsComponent(i, tempVisited, ignoreVertex, ignoreEdge);
        }
    }
}

int isConnectedWithoutVertex(int removeV) {
    int tempVisited[V] = {0};
    int startNode = (removeV == 0) ? 1 : 0;
    
    dfsComponent(startNode, tempVisited, removeV, -1);
    
    for (int i = 0; i < V; i++) {
        if (i != removeV && !tempVisited[i]) return 0; // Disconnected
    }
    return 1; // Connected
}

int isConnectedWithoutEdge(int edgeIdx) {
    int tempVisited[V] = {0};
    dfsComponent(0, tempVisited, -1, edgeIdx);
    
    for (int i = 0; i < V; i++) {
        if (!tempVisited[i]) return 0; // Disconnected
    }
    return 1; // Connected
}

int getVertexConnectivity() {
    for (int i = 0; i < V; i++) {
        if (!isConnectedWithoutVertex(i)) return 1; 
    }
    return 2;
}

int getEdgeConnectivity() {
    for (int i = 0; i < E; i++) {
        if (!isConnectedWithoutEdge(i)) return 1; // Found a bridge
    }
    return 2;
}

void dfsTree(int v) {
    visited[v] = 1;
    for (int i = 0; i < E; i++) {
        int next = -1;
        if (edges[i][0] == v) next = edges[i][1];
        else if (edges[i][1] == v) next = edges[i][0];

        if (next != -1 && !visited[next]) {
            branch[branchCount][0] = v;
            branch[branchCount][1] = next;
            branchCount++;
            dfsTree(next);
        }
    }
}

int isBranch(int u, int v) {
    for (int i = 0; i < branchCount; i++) {
        if ((branch[i][0] == u && branch[i][1] == v) || (branch[i][0] == v && branch[i][1] == u)) {
            return 1;
        }
    }
    return 0;
}

void identifyChords() {
    for (int i = 0; i < E; i++) {
        if (!isBranch(edges[i][0], edges[i][1])) {
            chord[chordCount][0] = edges[i][0];
            chord[chordCount][1] = edges[i][1];
            chordCount++;
        }
    }
}

void markComponent(int curr, int u, int v, int comp[]) {
    comp[curr] = 1;
    for (int i = 0; i < branchCount; i++) {
        int b1 = branch[i][0], b2 = branch[i][1];
        // Skip the removed branch
        if ((b1 == u && b2 == v) || (b1 == v && b2 == u)) continue;

        int next = -1;
        if (b1 == curr) next = b2;
        else if (b2 == curr) next = b1;

        if (next != -1 && !comp[next]) {
            markComponent(next, u, v, comp);
        }
    }
}

void findFundamentalCutSets() {
    printf("\n--- Fundamental Cut-Sets ---\n");
    for (int i = 0; i < branchCount; i++) {
        int u = branch[i][0];
        int v = branch[i][1];

        // Removing branch (u, v) splits tree into two components
        int compA[V] = {0};
        markComponent(u, u, v, compA);

        printf("Cut-set for Branch (%d, %d): { (%d, %d)", u, v, u, v);

        // A chord belongs to this cut-set if its endpoints are in different components
        for (int j = 0; j < chordCount; j++) {
            int cu = chord[j][0];
            int cv = chord[j][1];
            if (compA[cu] != compA[cv]) {
                printf(", (%d, %d)", cu, cv);
            }
        }
        printf(" }\n");
    }
}

void main() {
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    dfsTree(0);

    printf("\nSpanning Tree Branches:\n");
    for (int i = 0; i < branchCount; i++) {
        printf("Branch %d: (%d, %d)\n", i + 1, branch[i][0], branch[i][1]);
    }

    identifyChords();

    printf("\nChords:\n");
    for (int i = 0; i < chordCount; i++) {
        printf("Chord %d: (%d, %d)\n", i + 1, chord[i][0], chord[i][1]);
    }

    int vConn = getVertexConnectivity();
    int eConn = getEdgeConnectivity();

    printf("\n--- Connectivity Values ---\n");
    printf("Vertex Connectivity (kappa): %d\n", vConn);
    printf("Edge Connectivity (lambda): %d\n", eConn);

    findFundamentalCutSets();

    if (vConn <= 1) {
        printf("Graph is SEPARABLE");
    } else {
        printf("Graph is NON-SEPARABLE (biconnected)");
    }
}