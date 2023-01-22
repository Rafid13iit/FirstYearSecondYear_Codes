#include <graphics.h>
#include <conio.h>

void drawButton(int x, int y, int width, int height) {
    line(x, y, width, height);
    line(x, y+20, width, height+20);
    line(x, y+40, width, height+40);
}

void showList() {
    int y = 50;
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);

    outtextxy(400, y, "MENU");
    y += 60;

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    outtextxy(50, y, "BFS");
    y += 40;
    outtextxy(50, y, "DFS");
    y += 40;
    outtextxy(50, y, "Dijkstra's");
    y += 40;
    outtextxy(50, y, "Minimum spanning tree");
    y += 40;
    outtextxy(50, y, "Topological sorting");
    y += 40;
    outtextxy(50, y, "Articulation point");
    y += 40;
    outtextxy(50, y, "Euclerian path");
    y += 40;
    outtextxy(50, y, "Greedy best first search");
    y += 40;
    outtextxy(50, y, "Krusakal's algorithm");
    y += 40;
    outtextxy(50, y, "Prim's algorithm");
}

int main() {
    int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(900, 600);
    //initwindow() function is used instead of initgraph()

    drawButton(50, 50, 100, 50);

    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    outtextxy(350, 200, "Welcome");
    outtextxy(425, 250, "to");
    outtextxy(260, 300, "Graph Algorithms");

    while (1) {
        int x = mousex();
        int y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (x > 50 && x < 150 && y > 50 && y < 80) {
                // button was clicked
                cleardevice();
                showList();
                break;
            }
        }
    }
    getch();
    closegraph();
    return 0;
}
