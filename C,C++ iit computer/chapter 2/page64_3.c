
#include<stdio.h>
int Xor(int a, int b);
int main(){
    int p,q;

    printf("Enter p (0 or 1)");
    scanf("%d",&p);
    printf("Enter q (0 or 1)");
    scanf("%d",&q);
    printf("p and q: %d\n",p&&q);
    printf("p or q: %d\n",p||q);
    printf("p Xor q: %d\n",Xor(p,q));

    return 0;

}
int Xor(int a,int b){
    return  (a||b)&&!(a && b);
}

