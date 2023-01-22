#include<stdio.h>
int main(){
    float area,r,l,w,b,h;
    printf("Which area you want to calculate\nCirle, Rectangle, Triangle?\nEnter the first letter: \n");
    char a;
    scanf("%c",&a);
    if(a=='C'){
        printf("Enter the radius ");
        scanf("%f",&r);
        area=3.14*r*r;
        printf("Area is %f",area);
    }
    else if(a=='R'){
        printf("Enter the lenth ");
        scanf("%f",&l);
        printf("Enter the width ");
        scanf("%f",&w);
        area=l*w;
        printf("Area is %f",area);
    }
    else{
        printf("Enter the base ");
        scanf("%f",&b);
        printf("Enter the height ");
        scanf("%f",&h);
        area=.5*b*h;
        printf("Area is %f",area);
    }
}
