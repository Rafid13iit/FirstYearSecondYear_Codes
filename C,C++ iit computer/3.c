#include<stdio.h>
int main(){
 int n;
 scanf("%d",&n);
 n=(n*10000)%360;
  if(n==0)printf("zero angle");
    else if(0<n && n<90)printf("acute angle");
    else if(n==90)printf("right angle");
    else if(90<n && n<180)printf("obtuse angle");
    else if(n==180)printf("straight angle");
    else if(180<n && n<360) printf("reflex angle");

return 0;
}
