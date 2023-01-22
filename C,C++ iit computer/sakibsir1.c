#include<stdio.h>
double add(double X,double Y);
double sub(double X,double Y);
double mul(double X,double Y);
double div(double X,double Y);
int main()
{
    double a,b;
    char ch;

     printf("what do you want to do?\n");
    scanf("%c",&ch);

    printf("please enter two numbers\n");
    scanf("%lf%lf",&a,&b);

    if(ch=='+'){
        printf("the result is %lf",add(a,b));
    }
    else if(ch=='-'){
         printf("the result is %lf",sub(a,b));
    }
    else if(ch=='*'){
         printf("the result is %lf",mul(a,b));
    }
    else{
         printf("the result is %lf",div(a,b));
    }
    return 0;
}


double add(double X,double Y)
{
    return X+Y;
}
double sub(double X,double Y)
{
    return X-Y;
}
double mul(double X,double Y)
{
    return X*Y;
}
double div(double X,double Y)
{
    return X/Y;
}



