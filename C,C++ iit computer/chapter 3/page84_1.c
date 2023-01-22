#include<stdio.h>
int main(){
    int a,i=0;
    float s,v,t;
    printf("Enter the number of driving time ");
    scanf("%d",&a);
    while(i<a){
       printf("Enter the av speed: ");
       scanf("%f",&v);
       printf("Enter the distance: ");
       scanf("%f",&s);
       printf("Driving time is %f\n",s/v);
       i++;
    }
}
