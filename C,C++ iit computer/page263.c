#include <stdio.h>
#include <stdlib.h>
int main ()
{
    char str[] = "This is a file system test.\n";
    FILE *fp;
    char *p;
    int i;

    /*Open my file for output*/
    if ((fp = fopen("ra.txt","w")) == NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    //write str to disk
    p = str;
    while (*p){
        if (fputc(*p, fp) == EOF){
            printf("Error writing file.\n");
            exit(1);
        }
        p++;
    }
    fclose(fp);

    //open myfile for input
    if ((fp = fopen("myfile.txt", "r")) == NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    // read back th file
    for (;;){
        i = fgetc(fp);
        if (i == EOF) break;
        putchar(i);
    }
    fclose(fp);

    return 0;
}
