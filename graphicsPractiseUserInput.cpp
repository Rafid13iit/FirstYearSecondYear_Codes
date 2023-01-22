#include <graphics.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int nodes, edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    if (nodes < 1) {
        printf("Invalid number of nodes.\n");
        return 0;
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    if (edges < 0) {
        printf("Invalid number of edges.\n");
        return 0;
    }

    int x[nodes], y[nodes], i, j, u, v;
    //Read nodes positions
    for (i = 0; i < nodes; i++) {
        printf("Enter x and y coordinates of node %d :", i+1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Create nodes
    for (i = 0; i < nodes; i++) {
        circle(x[i], y[i], 20);
    }

    //Read edges connections
    for (i = 0; i < edges; i++) {
        printf("Enter the nodes to connect by edge %d :", i+1);
        scanf("%d %d", &u, &v);
        if (u < 1 || u > nodes || v < 1 || v > nodes) {
            printf("Invalid nodes.\n");
            return 0;
        }
        //Create edges
        line(x[u-1], y[u-1], x[v-1], y[v-1]);
    }

    getch();
    closegraph();
    return 0;
}
