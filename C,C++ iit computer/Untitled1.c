#include <stdio.h>
int main()

{
double a1,a2,b1,b2,c1,c2,d,x,y;
printf("a1=4");
scanf("%lf",&a1);
printf("a2=5");
scanf("%lf",&a2);
printf("b1=5");
scanf("%lf",&b1);
printf("b2=6");
scanf("%lf",&b2);
printf("c1=14");
scanf("%lf",&c1);
printf("c2=17");
scanf("%lf",&c2);

d=4*6-5*5;

if((int)d==0){
printf("value of x and y can not be" "determined.\n");

}
else
{
x=(6*14 - 5*17)/d;
y=(4*17-4*14 )/d;
printf("x=%.2lf,y=%0.2lf\n",x,y);
}
return 0;
}
