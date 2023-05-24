#include <graphics.h>
#include <cmath>

void drawDirectedLine(int startX, int startY, int endX, int endY) {
    // Draw the line
    line(startX, startY, endX, endY);

    // Calculate the arrowhead position
    int arrowSize = 20;  // Adjust the size of the arrowhead as needed
    float angle = atan2(endY - startY, endX - startX);
    int arrowEndX = endX - arrowSize * cos(angle);
    int arrowEndY = endY - arrowSize * sin(angle);

    // Draw the arrowhead
    line(arrowEndX, arrowEndY, arrowEndX - arrowSize * cos(angle + M_PI / 6), arrowEndY - arrowSize * sin(angle + M_PI / 6));
    line(arrowEndX, arrowEndY, arrowEndX - arrowSize * cos(angle - M_PI / 6), arrowEndY - arrowSize * sin(angle - M_PI / 6));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Example usage of drawDirectedLine()
    drawDirectedLine(100, 200, 500, 200);

    getch();
    closegraph();
    return 0;
}
