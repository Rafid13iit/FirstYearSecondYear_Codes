#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int i, j, n, t = 0;
    char code[50];

    printf("What is the course code that you teach?\n");
    scanf("%s", code);

    FILE *fp;
    fp = fopen("inserted_code.txt", "w");

    printf("How many students marks do you want to insert?\n");
    scanf("%d", &n);

    struct student{
        int roll;
        int mark;
    }stu[n];

    printf("Now insert students roll(between 1301 to 1336) & mark(out of 100) one by one :\n\n");

    for (i=0; i<n; i++){
        scanf("%d%d", &stu[i].roll, &stu[i].mark);

        if (stu[i].mark > 100 || stu[i].mark < 0 || stu[i].roll > 1336 || stu[i].roll < 1301){
            printf("Wrong roll or mark inserted!\n");
            printf("Please try again correctly.\n\n");
            i--;
        }
    }

    for (i=0; i<n; i++){
        fprintf(fp, "%d\t%d\n", stu[i].roll, stu[i].mark);
    }

    fclose(fp);

    return 0;

}
