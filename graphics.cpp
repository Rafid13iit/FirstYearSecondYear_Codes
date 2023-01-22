#include <graphics.h>

int main (int argc, char const *argv[])
{
   int gd = DETECT, gm;
   initgraph (&gd, &gm, (char*)"");

   circle(320, 240, 200);

   rectangle(100, 100, 400, 300);

   rectangle(50, 100, getmaxx() - 50, getmaxy() - 100);

   getch();
   closegraph();
   return 0;
}