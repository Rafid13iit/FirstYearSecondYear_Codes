#include <graphics.h>
#include <conio.h>

void drawButton(int x, int y, int width, int height) {
    line(x, y, width, height);
    line(x, y+20, width, height+20);
    line(x, y+40, width, height+40);
}

void drawListButton(int x, int y, int width, int height, char* text) {
    //drawButton(x, y, width, height);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    outtextxy(x + (width - textwidth(text)) / 2, y + (height - textheight(text)) / 2, text);
}

void showList() {
    int y = 50;
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
    outtextxy(250, y, "MENU");

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    int buttonWidth = 150, buttonHeight = 30;
    int x = 50;
    y += 50;
    drawListButton(x, y, buttonWidth, buttonHeight, "BFS");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "DFS");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Dijkstra's");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Minimum Spanning Tree");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Topological Sorting");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Articulation Point");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Eulerian Path");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Greedy Best First Search");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Kruskal's Algorithm");
    y += buttonHeight;
    drawListButton(x, y, buttonWidth, buttonHeight, "Prim's Algorithm");
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawButton(50, 50, 100, 50);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(200, 150, "Welcome");
    outtextxy(250, 200, "to");
    outtextxy(150, 250, "Graph Algorithms");

    while (1) {
        int x = mousex();
        int y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (x > 50 && x < 150 && y > 50 && y < 80) {
                cleardevice();
                showList();
                while (!kbhit()) {
                    int x = mousex();
                    int y = mousey();
                    if (ismouseclick(WM_LBUTTONDOWN)) {
                        if (x > 50 && x < 200 && y > 100 && y < 130) {
                            cleardevice();
                            outtextxy(250, 250, "BFS clicked!");
                            break;
                        } else if (x > 50 && x < 200 && y > 130 && y < 160) {
                            cleardevice();
                            outtextxy(250, 250, "DFS clicked!");
                            break;
                        } else if (x > 50 && x < 200 && y > 160 && y < 190) {
                            cleardevice();
                            outtextxy(250, 250, "Dijkstra's clicked!");
                            break;
                        } 
                        // Add checks for other buttons here
                    }
                }
                getch();
            }
        }
    }
    getch();
    closegraph();
    return 0;
}

