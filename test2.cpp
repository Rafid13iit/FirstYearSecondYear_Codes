#include <graphics.h>
#include <conio.h>

void drawButton(int x, int y, int width, int height, char* text) {
    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, width, height);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
    outtextxy((x + width)/2 - textwidth(text)/2, (y + height)/2 - textheight(text)/2, text);
}

void showButtons() {
    int y = 50;
    drawButton(50, y, 150, 40, "Button 1");
    y += 50;
    drawButton(50, y, 150, 40, "Button 2");
    y += 50;
    drawButton(50, y, 150, 40, "Button 3");
    y += 50;
    drawButton(50, y, 150, 40, "Button 4");
    y += 50;
    drawButton(50, y, 150, 40, "Button 5");
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    showButtons();

    while (!kbhit()) {
        int x = mousex();
        int y = mousey();
        if (ismouseclick(WM_LBUTTONDOWN)) {
            if (x > 50 && x < 200) {
                if (y > 50 && y < 90) {
                    // button 1 was clicked
                    cleardevice();
                    outtextxy(50, 50, "Button 1 was clicked!");
                    break;
                }
                else if (y > 100 && y < 140) {
                    // button 2 was clicked
                    cleardevice();
                    outtextxy(50, 50, "Button 2 was clicked!");
                    break;
                }
                else if (y > 150 && y < 190) {
                    // button 3 was clicked
                    cleardevice();
                    outtextxy(50, 50, "Button 3 was clicked!");
                    break;
                }
                else if (y > 200 && y < 240) {
                    // button 4 was clicked
                    cleardevice();
                    outtextxy(50, 50, "Button 4 was clicked!");
                    break;
                }
                else if (y > 250 && y < 290) {
                    // button 5 was clicked
                    cleardevice();
                    outtextxy(50, 50, "Button 5 was clicked!");
                    break;
                }
            }
        }
    }
    getch();
    closegraph();
    return 0;
}
