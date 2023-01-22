#include<stdio.h>
int main(){
    int answer,count;
    int again;
    for(count=1;count<11;count++){
        printf("What is %d + %d? ",count,count);
        scanf("%d",&answer);

        if(answer==count + count){
            printf("Right\n");
        }
        else{
            printf("sorry,you are wrong\n");
            printf("Try again\n");
            printf("What is %d + %d? ",count,count);
            scanf("%d",&answer);

        if(answer==count+count)printf("Right\n");
        else printf("wrong, the answer is %d? \n",count+count);
        }

    }
}

