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

int rank, nullity;

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < E; i++) {
        int next = -1;
        if (edges[i][0] == v) {
            next = edges[i][1];
        } else if (edges[i][1] == v) {
            next = edges[i][0];
        }

        if (next != -1 && visited[next] == 0) {
            branch[branchCount][0] = v;
            branch[branchCount][1] = next;
            branchCount++;

            dfs(next);
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

void identifyBranches() {
    for (int i = 0; i < E; i++) {
        if (!isBranch(edges[i][0], edges[i][1])) {
            chord[chordCount][0] = edges[i][0];
            chord[chordCount][1] = edges[i][1];
            chordCount++;
        }
    }
}

int findPathInTree(int curr, int target, int path[], int pathLen, int pathVisited[]) {
    if (curr == target) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d - ", path[i]);
        }
        printf("%d\n", target);
        return 1;
    }
    
    pathVisited[curr] = 1;
    
    for (int i = 0; i < branchCount; i++) {
        int next = -1;
        if (branch[i][0] == curr) next = branch[i][1];
        else if (branch[i][1] == curr) next = branch[i][0];
        
        if (next != -1 && !pathVisited[next]) {
            path[pathLen] = curr;
            if (findPathInTree(next, target, path, pathLen + 1, pathVisited)) {
                return 1;
            }
        }
    }
    return 0;
}

void findFundamentalCircuits() {
    printf("Fundamental Circuits\n");
    for (int i = 0; i < chordCount; i++) {
        int u = chord[i][0];
        int v = chord[i][1];
        
        printf("Circuit for chord (%d, %d): ", u, v);
        
        int path[V];
        int pathVisited[V] = {0};
        
        // Find path from u to v in the tree, then complete the cycle with the chord
        findPathInTree(u, v, path, 0, pathVisited);
    }
}

void calculateRankNullity() {
    rank = V - 1;
    nullity = E - V + 1;
}

void verifyResult() {
    printf("Number of Branches (Spanning Tree Edges): %d (Expected: %d)\n", branchCount, rank);
    printf("Number of Chords (Fundamental Circuits): %d (Expected: %d)\n", chordCount, nullity);
    
    if (branchCount == rank && chordCount == nullity) {
        printf("Verification SUCCESS.");
    } else {
        printf("Verification FAILED.");
    }
}

void main(){
    dfs(0);

    printf("Spanning Tree Branches\n");
    for (int i = 0; i < branchCount; i++) {
        printf("Branch %d: (%d, %d)\n", i + 1, branch[i][0], branch[i][1]);
    }

    identifyBranches();

    printf("Chords\n");
    for (int i = 0; i < chordCount; i++) {
        printf("Chord %d: (%d, %d)\n", i + 1, chord[i][0], chord[i][1]);
    }

    findFundamentalCircuits();

    calculateRankNullity();

    verifyResult();
}