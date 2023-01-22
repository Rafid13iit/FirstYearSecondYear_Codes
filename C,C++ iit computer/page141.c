#include <stdio.h>
int main ()
{
    int temp[31];
    int avg = 0, max, min, i, days;

    printf("How many days?\n");
    scanf("%d", &days);

    // taking input temperature and calculating avg
    printf("Input temperatures (in celcius):\n\n");
    for (i=0; i<days; i++){
        scanf("%d", &temp[i]);
        avg = avg + temp[i];
    }

    max = 200;
    min = -100;
    for (i=0; i<days; i++){

    }
}
