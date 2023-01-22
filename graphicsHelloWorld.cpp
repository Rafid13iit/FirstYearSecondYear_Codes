#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    //font, direction, and size 
    outtextxy(50, 50, "Hello World (TRIPLEX_FONT)"); 
    //to display the text at the specified coordinates
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(50, 100, "Hello World (SANS_SERIF_FONT)");
    
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
    outtextxy(50, 150, "Hello World (GOTHIC_FONT)");

    getch();
    closegraph();
    return 0;
}
