#include<stdio.h>
int main(){
    int i,j;
    for(i=1;i<=100;i++){
       printf("10 percent tip for %d$ is %f\n",i,(float)i*.1);
       printf("20 percent tip for %d$ is %f\n",i,(float)i*.2);
       printf("30 percent tip for %d$ is %f\n",i,(float)i*.3);
       printf("if you want to continue press 1, else 0\n");
       scanf("%d",&j);
       if(j==1){
        continue;
       }
       else break;
    }
}
