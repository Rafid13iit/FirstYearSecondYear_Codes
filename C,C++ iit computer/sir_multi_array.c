#include <stdio.h>
#include <string.h>
int main ()
{
    int iit_marks[2][6][3];

    int i, j, k, sum=0;

    for (i=0; i<2; i++){
        printf("Please input marks of CE, Lab, Final and see total mark: \n");

        for (j=0; j<6; j++){
            for (k=0; k<3; k++){

                scanf("%d", &iit_marks[i][j][k]);
                sum= sum + iit_marks[i][j][k];

            }
            printf("Total marks out of 100 is : %d\n\n", sum);
            sum = 0;
        }
    }

    return 0;
}
