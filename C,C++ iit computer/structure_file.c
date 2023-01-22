#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE *fp;
    fp = fopen("BSSE13.txt", "r");

    if (fp == NULL) printf("File is not opened!\n");

    else {
        printf("File is opened.\n");

        int num, i;

        printf("How many students data do you want to copy in variable?\n");
        scanf("%d", &num);



        // using structure here
        struct student {
            int roll;
            char name[50];
            float cgpa;
        } bsse13[num];

        for (i=0; i<num; i++){
            fscanf(fp, "%d%s%f", &bsse13[i].roll, bsse13[i].name, &bsse13[i].cgpa);
        }

        fclose(fp);

        for (i=0; i<num; i++){
            printf("%d\t%s\t%.2f", bsse13[i].roll, bsse13[i].name, bsse13[i].cgpa);
            printf("\n");
        }


        printf("\n\n");

        //sorting by structure
        int j;
        struct student temp;

        for (i=0; i<num; i++){
            for (j=i+1; j<num; j++){

                if (bsse13[i].cgpa < bsse13[j].cgpa){

                   temp = bsse13[i];
                   bsse13[i] = bsse13[j];
                   bsse13[j] = temp;
                }
            }
        }

        for (i=0; i<num; i++){
            printf("%d\t%s\t%.2f", bsse13[i].roll, bsse13[i].name, bsse13[i].cgpa);
            printf("\n");
        }



    }

    return 0;
}

