#include <stdio.h>
#include <math.h>

#define MAX 100


int main() {

    int n, i, j, p, q, flag;
    double eVectors[MAX][MAX];
    double V[MAX][MAX];
    double VT[MAX][MAX];
    double U[MAX][MAX];
    double eValues[MAX];
    double squareValues[MAX];
    double a[MAX][MAX], d[MAX][MAX], s[MAX][MAX], s1[MAX][MAX], s1t[MAX][MAX];
    double temp[MAX][MAX], phi, zero = 1e-5, max, pi = 3.141592;

    double A[MAX][MAX],AT[MAX][MAX],E[MAX][MAX];
    int matrixRow,matrixColumn;


    printf("Enter dimentions (row,col)->\n");
    scanf("%d%d",&matrixRow,&matrixColumn);
    printf("Enter The Matrix\n");
    for(int i=0;i<matrixRow;i++)
        {
        for(int j=0;j<matrixColumn;j++)
            {
            //printf("A[%d,%d]=",i+1,j+1);
            scanf("%lf",&A[i][j]);
            }
        }
        printf("Calculation for V and sigma matrix\n------------------------------------------------------------\n");
        double Atrow=matrixColumn,Atcol=matrixRow;
        //finding AT(A Transpose)
        for(int i=0;i<matrixRow;i++)
        {
        for(int j=0;j<matrixColumn;j++)
        {
            AT[j][i]=A[i][j];
        }

        }

        printf("\nA Matrix is:\n\n");
        for(int i=0;i<matrixRow ;i++)
        {
        for(int j=0;j<matrixColumn;j++)
        {
            printf("%lf  ",A[i][j]);
        }
        printf("\n");
        }

        printf("\nAT(Transpose) Matrix is:\n\n");
        for(int i=0;i<Atrow ;i++)
        {
        for(int j=0;j<Atcol;j++)
        {
            printf("%lf  ",AT[i][j]);
        }
        printf("\n");
        }




    //Forming AT*A
    for(int i=0;i<Atrow;i++)
    {
        for(int j=0;j<=matrixColumn;j++)
        {
            a[i][j]=0;
            for(int k=0;k<Atcol;k++)
            {
                a[i][j]+=AT[i][k]*A[k][j];
            }
        }
    }
    n=Atrow;
    printf("\nSymmetric Matrix is:\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        printf("%lf  ",a[i][j]);
        }
        printf("\n");
    }

    /*
    printf("Enter the elements row wise \n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)  scanf ("%lf", &a[i][j]);
    }
    */
    printf("\nThe given matrix is\n\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf ("%8.4f ", a[i][j]);
        printf ("\n");
    }
    printf ("\n");

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
        d[i][j]= a[i][j];
        if(i==j)
            s[i][j]= 1;
        else
            s[i][j]= 0;
        }
    }

    do {
        flag= 0;
        p=0; q=1;
        max= fabs(d[p][q]);

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j) {
            if (max < fabs(d[i][j])) {
                max= fabs(d[i][j]);
                p= i;
                q= j;
            }
            }
        }
        }

        if(d[p][p]==d[q][q]) {
        if (d[p][q] > 0)
            phi= phi/4;
        else
            phi= -phi/4;
        }
        else {
        phi=0.5*atan(2*d[p][q]/(d[p][p]-d[q][q]));
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i==j) {
            s1[i][j]= 1;
            s1t[i][j]= 1;
            }
            else {
            s1[i][j]= 0;
            s1t[i][j]= 0;
            }
        }
        }

        s1[p][p]= cos(phi);
        s1t[p][p]= s1[p][p];

        s1[q][q]= cos(phi);
        s1t[q][q]= s1[q][q];

        s1[p][q]= -sin(phi);
        s1[q][p]= sin(phi);

        s1t[p][q]= s1[q][p];
        s1t[q][p]= s1[p][q];

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            temp[i][j]= 0;
            for(p=0; p<n; p++)  temp[i][j]+= s1t[i][p]*d[p][j];
        }
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            d[i][j]= 0;
            for(p=0; p<n; p++)  d[i][j]+= temp[i][p]*s1[p][j];
        }
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            temp[i][j]= 0;
            for(p=0; p<n; p++)  temp[i][j]+= s[i][p]*s1[p][j];
        }
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++)  s[i][j]= temp[i][j];
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j)
            if(fabs(d[i][j]) > zero) flag= 1;
        }
        }
    }while(flag==1);

    printf("The eValues are:\n\n");
    for(i=0; i<n; i++)
    {

        printf("%8.4lf ",d[i][i]);
        eValues[i]=d[i][i];
    }

    // sorting Decreasing order of eigen_values
    for (int c = 0 ; c < n - 1; c++)
    {
        for (int d = 0 ; d < n - c - 1; d++)
        {
        if (eValues[d] < eValues[d+1])
        {
            double swap = eValues[d];
            eValues[d]   = eValues[d+1];
            eValues[d+1] = swap;
        }
        }
    }
    printf("\nDecresing order of eigen values are:\n");
    for(i=0; i<n; i++)
    {

        printf("%8.4lf ",eValues[i]);

    }
    printf("\nThe corresponding eigenvectors are:\n\n");

    /*for(j=0; j<n; j++) {
        printf("(");
        for(i=0; i<n-1; i++)
        printf("% 8.4lf,",s[i][j]);
        printf("%8.4lf )^T\n",s[n-1][j]);
    }
    */
    printf("\n\n");
    /////////////////////////////////////////

    for(j=0; j<n; j++) {
        printf("(");
        squareValues[j]=0;
        for(i=0; i<n; i++){
        printf("% 8.4lf,",s[i][j]);
        eVectors[j][i]=s[i][j];
        squareValues[j]=squareValues[j]+(s[i][j]*s[i][j]);
        }
        printf(")^T\n");
    }


    //Normalizing Eigenvectors
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            eVectors[i][j]=(eVectors[i][j]/(sqrt(squareValues[i])));
        }
    }
    //Forming V matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            V[j][i]=eVectors[i][j];
        }
    }

    //forming VT matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            VT[i][j]=V[j][i];
        }
    }
    //printing V matrix
    printf("V matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%lf\t",V[i][j]);
        }
        printf("\n");
    }


    //printing VT matrix
    printf("VT matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%lf\t",VT[i][j]);
        }
        printf("\n");
    }

    //Forming E matrix;
    int nth_eigen_value=0;
    for(int i=0;i<matrixRow;i++)
    {
        for(int j=0;j<matrixColumn;j++)
        {
        if(i==j)
        {
            E[i][j]=sqrt(eValues[nth_eigen_value]);
            nth_eigen_value++;
        }
        else{
            E[i][j]=0;
            }
        }
    }


    printf("E matrix is:\n");
    for(int i=0;i<matrixRow;i++)
    {
        for(int j=0;j<matrixColumn;j++)
        {
            printf("%lf ",E[i][j]);
        }
        printf("\n");
    }

    printf("Calculation for U  matrix\n------------------------------------------------------------\n");

    //  Forming Symmetric Matrix Multiplying (A*AT) Matrices
    for(int i=0;i<matrixRow;i++)
    {
        for(int j=0;j<Atcol;j++)
        {
        a[i][j]=0;
        for(int k=0;k<matrixColumn;k++)
        {
            a[i][j]+=A[i][k]*AT[k][j];
        }
        }
    }

    n=matrixRow;
    printf("\nSymmetric Matrix is:\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        printf("%lf  ",a[i][j]);
        }
        printf("\n");
    }


    printf("\nThe given matrix is\n\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf ("%8.4f ", a[i][j]);
        printf ("\n");
    }
    printf ("\n");

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
        d[i][j]= a[i][j];
        if(i==j)
            s[i][j]= 1;
        else
            s[i][j]= 0;
        }
    }

    do {
        flag= 0;
        p=0; q=1;
        max= fabs(d[p][q]);

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j) {
            if (max < fabs(d[i][j])) {
                max= fabs(d[i][j]);
                p= i;
                q= j;
            }
            }
        }
        }

        if(d[p][p]==d[q][q]) {
        if (d[p][q] > 0)
            phi= phi/4;
        else
            phi= -phi/4;
        }
        else {
        phi=0.5*atan(2*d[p][q]/(d[p][p]-d[q][q]));
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i==j) {
            s1[i][j]= 1;
            s1t[i][j]= 1;
            }
            else {
            s1[i][j]= 0;
            s1t[i][j]= 0;
            }
        }
        }

        s1[p][p]= cos(phi);
        s1t[p][p]= s1[p][p];

        s1[q][q]= cos(phi);
        s1t[q][q]= s1[q][q];

        s1[p][q]= -sin(phi);
        s1[q][p]= sin(phi);

        s1t[p][q]= s1[q][p];
        s1t[q][p]= s1[p][q];

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            temp[i][j]= 0;
            for(p=0; p<n; p++)  temp[i][j]+= s1t[i][p]*d[p][j];
        }
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            d[i][j]= 0;
            for(p=0; p<n; p++)  d[i][j]+= temp[i][p]*s1[p][j];
        }
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            temp[i][j]= 0;
            for(p=0; p<n; p++)  temp[i][j]+= s[i][p]*s1[p][j];
        }
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++)  s[i][j]= temp[i][j];
        }

        for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j)
            if(fabs(d[i][j]) > zero) flag= 1;
        }
        }
    }while(flag==1);

    printf("The eValues are:\n\n");
    for(i=0; i<n; i++)
    {

        printf("%8.4lf ",d[i][i]);
        eValues[i]=d[i][i];
    }

    // sorting Decreasing order of eigen_values
    for (int c = 0 ; c < n - 1; c++)
    {
        for (int d = 0 ; d < n - c - 1; d++)
        {
        if (eValues[d] < eValues[d+1])
        {
            double swap = eValues[d];
            eValues[d]   = eValues[d+1];
            eValues[d+1] = swap;
        }
        }
    }
    printf("\nDecresing order of eValues are:\n");
    for(i=0; i<n; i++)
    {

        printf("%8.4lf ",eValues[i]);

    }
    printf("\nThe corresponding eigenvectors are:\n\n");


    for(j=0; j<n; j++) {
        printf("(");
        squareValues[j]=0;
        for(i=0; i<n; i++){
        printf("% 8.4lf,",s[i][j]);
        eVectors[j][i]=s[i][j];
        squareValues[j]=squareValues[j]+(s[i][j]*s[i][j]);
        }
        printf(")^T\n");
    }
    printf("\n\n");



    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            eVectors[i][j]=(eVectors[i][j]/(sqrt(squareValues[i])));
        }
    }



    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            U[j][i]=eVectors[i][j];
        }
    }
    //printing V matrix
    printf("U matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%lf\t",U[i][j]);
        }
        printf("\n");
    }



}







