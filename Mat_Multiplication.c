#include<stdio.h>
int main ()
{
  int mat1[2][3] = { {0, 1, 2}, {3, 4, 5} };
  int mat2[3][2] = { {1, 2}, {3, 4}, {5, 6} };
  int mul[2][2], i, j, k;

  printf ("matrix 1 is :\n");
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  printf ("%d   ", mat1[i][j]);
	  if (j == 3 - 1)
	    {
	      printf ("\n\n");
	    }
	}
    }

  printf ("matrix 2 is :\n");
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 2; j++)
	{
	  printf ("%d   ", mat2[i][j]);
	  if (j == 2 - 1)
	    {
	      printf ("\n\n");
	    }
	}
    }


  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)
        {
        mul[i][j] = 0;
        for (k = 0; k < 3; k++)
            {
            mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

  printf ("The product of the two matrices is: \n");
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)
	{
	  printf ("%d\t", mul[i][j]);
	}
      printf ("\n");
    }
  return 0;
}