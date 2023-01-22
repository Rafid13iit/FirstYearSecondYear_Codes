#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    // draw nodes
    for (int i = 0; i < 4; i++) {
        setcolor(BLUE);
        circle(i*50+RADIUS, RADIUS, RADIUS);
        setcolor(BLACK);
        outtextxy(i*50+RADIUS-5, RADIUS-10, itoa(i, buffer,10));
    }
    // draw edges
    int adjacencyMatrix[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (adjacencyMatrix[i][j]) {
                setcolor(LIGHTGRAY);
                line(i*50+RADIUS, j*50+RADIUS, (i+1)*50-RADIUS, (j+1)*50-RADIUS);
            }
        }
    }
    // perform Dijkstra's algorithm starting from node 0
    dijkstra(0, adjacencyMatrix);
    getch();
    closegraph();
    return 0;
}
