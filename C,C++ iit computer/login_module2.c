#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    FILE *fp;
    fp = fopen("registration.txt", "r");

    char name1[1000];
    char userid1[1000];
    char pass1[20];
    int i, j, count1 = 0, count2 = 0;

    struct reg{
            char name[1000];
            char userid[1000];
            char pass[20];
    } teacher[7];

    for (i=1; i<7; i++){
            fscanf(fp, "%s%s%s", teacher[i].name, teacher[i].userid, teacher[i].pass);
    }

    for(;;){
        printf("Please input your userID: ");
        scanf("%s", userid1);

        printf("Please input your password: ");
        scanf("%s", pass1);

        for (i=0; i<7; i++){
            if (strcmp(userid1, teacher[i].userid) == 0){
                count1 = 1;
            }
            else count1 = 0;

            for (j=0; j<strlen(teacher[i].pass); j++){
                teacher[i].pass[j] = teacher[i].pass[j] - 1;
            }

            if (strcmp(pass1, teacher[i].pass) == 0){
                count2 = 1;
                break;
            }
            else count2 = 0;
        }

        if (count1 == 0){
            printf("userID does not found!\n");
            printf("Please try again.\n");
            continue;
        }

        if (count2 == 0){
            printf("Password does not match!\n");
            printf("Please try again.\n");
            continue;
        }

        else {
            printf("Hello, %s\n", teacher[i].name);
            break;
        }
    }

    fclose(fp);

    return 0;
}
