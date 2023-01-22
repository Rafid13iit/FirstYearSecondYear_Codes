#include<stdio.h>
int main(){
    int answer,count,chances,right;

    for(count=1;count<11;count++){
        printf("What is %d + %d",count,count);
        scanf("%d",&answer);

        if(answer == count+count) printf("Right!\n");
        else{
            printf("Sorry,You're wrong.\n");
            printf("Try again");

            right = 0;
            for(chances=0; chances<3 && !right; chances++){
                printf("What is %d + %d?",count,count);
                scanf("%d",&answer);

                if(answer == count + count){
                    printf("Right!\n");
                    right=1;
                }
            }
            if(!right)
                printf("The answer is %d.\n",count+count);
        }

    }
    return 0;
}
