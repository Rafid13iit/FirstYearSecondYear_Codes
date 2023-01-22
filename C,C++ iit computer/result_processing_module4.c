#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int i, j, n;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7;

    fp1 = fopen("cse101.txt", "r");
    fp2 = fopen("cse102.txt", "r");
    fp3 = fopen("math.txt", "r");
    fp4 = fopen("socio.txt", "r");
    fp5 = fopen("stat.txt", "r");
    fp6 = fopen("se106.txt", "r");
    fp7 = fopen("result.txt", "w");

    printf("How many students result do you want to make?\n");
    scanf("%d", &n);

    struct student{
        char name[6][50];
        int roll[6];
        int mark[6];
    }stu[n];

    for (i=0; i<n; i++){
        j = 0;
        fscanf(fp1, "%d%s%d", &stu[i].roll[j], stu[i].name[j], &stu[i].mark[j]);
    }

    for (i=0; i<n; i++){
        j = 1;
        fscanf(fp2, "%d%s%d", &stu[i].roll[j], stu[i].name[j], &stu[i].mark[j]);
    }

    for (i=0; i<n; i++){
        j = 2;
        fscanf(fp3, "%d%s%d", &stu[i].roll[j], stu[i].name[j], &stu[i].mark[j]);
    }

    for (i=0; i<n; i++){
        j = 3;
        fscanf(fp4, "%d%s%d", &stu[i].roll[j], stu[i].name[j], &stu[i].mark[j]);
    }

    for (i=0; i<n; i++){
        j = 4;
        fscanf(fp5, "%d%s%d", &stu[i].roll[j], stu[i].name[j], &stu[i].mark[j]);
    }

    for (i=0; i<n; i++){
        j = 5;
        fscanf(fp6, "%d%s%d", &stu[i].roll[j], stu[i].name[j], &stu[i].mark[j]);
    }

    for (j=0; j<6; j++){
        for (i=0; i<n; i++){
            printf("%d\t%s\t%d\n", stu[i].roll[j], stu[i].name[j], stu[i].mark[j]);
        }
        printf("\n");
    }


    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
    fclose(fp7);

    return 0;
}
