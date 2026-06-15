#include <stdio.h>
void main(){
    int vertex, edges;
    printf("Enter Number of Vertices: ");
    scanf("%d", &vertex);

    printf("Enter Number of Edges: ");
    scanf("%d", &edges);

    int arrEdges[edges][2];
    for (int i = 0; i < edges; i++) {
        printf("Enter Source for %d edge: ", i);
        scanf("%d", &arrEdges[i][0]);

        printf("Enter Destination for %d edge: ", i);
        scanf("%d", &arrEdges[i][1]);

    }
    for (int i = 0; i < vertex; i++) {
        printf("%d -> ", i);
        for (int j = 0; j < edges; j++) {
            if (arrEdges[j][0] == i) {
                printf("%d ", arrEdges[j][1]);
            }
        }
        printf("\n");
    }
}