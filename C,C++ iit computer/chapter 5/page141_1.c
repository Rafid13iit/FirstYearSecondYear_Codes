#include <stdio.h>
int main ()
{
    int temp[31], i, min, max, avg;
    int days;

    printf("How many days in the month?\n");
    scanf("%d", &days);

    for (i=0; i<days; i++){
        printf("Enter temp for %d day : ",  i+1);
        scanf("%d", &temp[i]);
    }

    //find average
    avg = 0;
    for (i=0; i<days; i++){
        avg = avg + temp[i];
    }

    printf("Average temperature : %d\n", avg / days);

    //find min and max
    min = 200; // initialize min and max
    max = 0;
    for (i=0; i<days; i++){
        if (min > temp[i]) min = temp[i];
        if (max < temp[i]) max = temp[i];
    }

    printf("Min temp : %d\n", min);
    printf("Max temp : %d\n", max);

    return 0;
}
