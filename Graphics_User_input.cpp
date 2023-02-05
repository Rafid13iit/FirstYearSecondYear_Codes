#include <graphics.h>
#include <iostream>
#include <string>
#include <sstream>

int main() {
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "");
   
   outtextxy(10, 10, "Enter first number: ");
   std::string str1;
   char ch = getch();
   while (ch != 13) {  // 13 is the ASCII value for the Enter key
      str1 += ch;
      std::stringstream ss;
      ss << str1;
      outtextxy(150, 10, ss.str().c_str());
      ch = getch();
   }
   int num1 = atoi(str1.c_str());
   
   outtextxy(10, 30, "Enter second number: ");
   std::string str2;
   ch = getch();
   while (ch != 13) {
      str2 += ch;
      std::stringstream ss;
      ss << str2;
      outtextxy(150, 30, ss.str().c_str());
      ch = getch();
   }
   int num2 = atoi(str2.c_str());
   
   int result = num1 + num2;
   outtextxy(10, 50, "The sum of the two numbers is: ");
   std::stringstream ss;
   ss << result;
   outtextxy(10, 70, ss.str().c_str());
   
   getch();
   closegraph();
   return 0;
}
