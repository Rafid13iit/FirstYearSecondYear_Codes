#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Create nodes
    int x1 = 50, y1 = 50, x2 = 100, y2 = 100, x3 = 150, y3 = 150, x4 = 200, y4 = 50;
    circle(x1, y1, 20);
    circle(x2, y2, 20);
    circle(x3, y3, 20);
    circle(x4, y4, 20);

    // Create edges
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x1, y1, x4, y4);

    getch();
    closegraph();
    return 0;
}
