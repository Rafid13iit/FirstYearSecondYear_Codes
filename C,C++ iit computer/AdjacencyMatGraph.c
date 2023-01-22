#iclude <stdio.h>
#include <stdlib.h>
int main ()
{
    int vertix, edge, i, j;

    printf("How many Nodes in the Graph?\n");
    scanf("%d", &vertix);

    int  A[vertix];
    printf("Input the nodes : ");

    for (i=0; i<vertix; i++){
        scanf("%d", &A[i]);
    }

    printf("How many Edges in the Graph?\n");
    scanf("%d", &edge);

    int E[edge][2];

    for (i=0; i<edge; i++){
        scanf("%d%d", &E[i][0], &E[i][1]);
    }
}
