#include <stdio.h>
void error(int err_num);
int main ()
{
    char *p[] = {
    "Input exceeds field width",
    "Out of range",
    "Printer not turned on",
    };

    void error(int err_num){
        printf(p[err_num]);
    }

    return 0;
}
