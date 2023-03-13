//Armstrong number is a number 
//that is equal to the sum of cubes of its digits

#include <stdio.h>
int main ()
{
    int startNum, endNum, sum = 0;

    printf("Test Data:\n");
    printf("Input starting number of range: ");
    scanf("%d", &startNum);
    printf("Input ending number of range: ");
    scanf("%d", &endNum);


    printf("Armstrong numbers in given range are : ");
    for (int i = startNum; i <= endNum; i++){
        for (int j = i; j > 0; ){
            if (j % 10 != 0) {
                sum += (j % 10) * (j % 10) * (j % 10);
                j /= 10;
            }

            else {
                j /= 10;
            };
        }

        if (sum == i) printf("%d ", i);
        sum = 0;
    }

    return 0;
}