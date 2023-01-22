#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int Aa[10] = {1, 4, 2, 5, 66, 43, 64, 23, 13, 9};



    sort (Aa, Aa + 10);  //sorting in ascending order

    for (int i=0; i<10; i++){
        printf("%d ", Aa[i]);
    }
    printf("\n\n");



    sort (Aa, Aa + 10, greater<int>()); //sorting in descending order

    for (int i=0; i<10; i++){
        printf("%d ", Aa[i]);
    }
    printf("\n\n");



    reverse (Aa, Aa + 10); //use of REVERSE func

    for (int i=0; i<10; i++){
        printf("%d ", Aa[i]);
    }
    printf("\n\n");


    int Bb[10] = {1, 4, 2, 5, 66, 43, 64, 23, 13, 9};


    sort (Bb+4, Bb+10); // sort [... , ...)

    for (int i=0; i<10; i++){
        printf("%d ", Bb[i]);
    }
    printf("\n\n");


    int Cc[10] = {1, 4, 2, 5, 66, 43, 64, 23, 13, 9};

    sort (Cc+4, Cc+6); // sort [... , ...)

    for (int i=0; i<10; i++){
        printf("%d ", Cc[i]);
    }


    return 0;
}
