#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
    int i, j;
    FILE *fp;
    fp = fopen("registration.txt", "w");

    struct reg{
            char name[1000];
            char userid[1000];
            char pass[20];
    } teacher[7];

    printf("Enter name, userID & 8 characters long password:\n\n");
    printf("The data of admin user:\n");
    scanf("%s%s%s", teacher[0].name, teacher[0].userid, teacher[0].pass);

    for (j=0; j<strlen(teacher[0].pass); j++){
        teacher[0].pass[j] = teacher[0].pass[j] + 1;
    }
    teacher[0].pass[strlen(teacher[0].pass)] = '\0';


    printf("\nThe data of other users:\n\n");

    for (i=1; i<7; i++){

        scanf("%s%s%s", teacher[i].name, teacher[i].userid, teacher[i].pass);

        for(;;){
            if(strlen(teacher[i].pass) != 8){
                printf("Not a 8 character long password.\n");
                printf("Enter 8 character long password:\n");
                scanf("%s", teacher[i].pass);
            }

            if (strlen(teacher[i].pass) != 8) continue;
            else break;
        }

        for (j=0; j<strlen(teacher[i].pass); j++){
            teacher[i].pass[j] = teacher[i].pass[j] + 1;
        }
        teacher[i].pass[strlen(teacher[i].pass)] = '\0';

        printf("\n");
    }


    for (i=0; i<7; i++){
        fprintf(fp, "%s\t%s\t%s\n", teacher[i].name, teacher[i].userid, teacher[i].pass);
    }



    for (i=0; i<7; i++){
        printf("%s\t%s\t%s\n", teacher[i].name, teacher[i].userid, teacher[i].pass);

    }

    fclose(fp);

    return 0;
}
