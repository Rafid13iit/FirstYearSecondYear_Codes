#include<stdio.h>
void f();
int main()
{
    f();
    f();
    f();
    return 0;


}
void f()
{
    int i=10;
    printf("%d ",i);
}

