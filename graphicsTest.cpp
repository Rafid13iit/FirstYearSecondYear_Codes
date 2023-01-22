#include <graphics.h>
#include <stdio.h>

int main()
{
    freopen ("TestGraphics.txt", "r", stdin);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); //initializes the graphics window from the graphics.h library

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
        setcolor(YELLOW);
        circle(x[i], y[i], 20);
        setcolor(WHITE);
        outtextxy(x[i]-5,y[i]-5, (char*)std::to_string(i+1).c_str());
    }

    //Read edges connections
    for (i = 0; i < edges; i++) {
        printf("Enter the nodes to connect by edge %d :", i+1);
        scanf("%d %d", &u, &v);
        u--;
        v--;
        setcolor(RED);
        line(x[u], y[u], x[v], y[v]);
    }

    getch();
    closegraph(); //closes the graphics window
    return 0;
}
