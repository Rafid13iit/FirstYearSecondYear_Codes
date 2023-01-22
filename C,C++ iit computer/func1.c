#include<stdio.h>

float add(float a,float b);
float sub(float a,float b);
float mul(float a,float b);
float div(float a,float b);

int main()
{
   float a,b;

    printf("please enter two numbers:\n");
    scanf("%f%f",&a,&b);

    float ab=add(a,b);
    float bc=sub(a,b);
    float cd=mul(a,b);
    float de=div(a,b);

    printf("\nAdd: %0.0f, sub: %0.0f, Mul: %0.0f & Div: %f",ab,bc,cd,de);

    return 0;
}

float add(float a,float b){
return a+b;}

float sub(float a,float b){
return a-b;}

float mul(float a,float b){
return a*b;}

float div(float a,float b){
return a/b;}
