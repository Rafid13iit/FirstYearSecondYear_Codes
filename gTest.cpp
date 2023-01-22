#include <graphics.h>
#include <stdio.h>

void drawGraph(int data[], int numPoints) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int max = data[0];
    for (int i = 1; i < numPoints; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    int x = 50, y = getmaxy() - 50;
    int xScale = (getmaxx() - 100) / numPoints;
    int yScale = (getmaxy() - 100) / max;

    for (int i = 0; i < numPoints; i++) {
        int x1 = x + (i * xScale);
        int y1 = y - (data[i] * yScale);
        int x2 = x + ((i + 1) * xScale);
        int y2 = y - (data[i + 1] * yScale);
        line(x1, y1, x2, y2);
    }

    getch();
    closegraph();
}

int main() {
    int data[] = {3, 5, 7, 9, 11, 13, 15};
    int numPoints = sizeof(data) / sizeof(data[0]);
    drawGraph(data, numPoints);
    return 0;
}
