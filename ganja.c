#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char spt,a,b,fpt;int states;
   printf("Enter the states to construct a string including string 111\n");
    scanf("%c",&spt);
    fpt=spt+3;
     printf("%c",fpt);
    getchar();int c=0;
    char s[1000];
    gets(s);


    char pspt,pfpt,k;
    pspt=spt;pfpt=fpt;

  for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='0')
        {
            pspt=pspt;
            printf("(%c,%c)->%c\n",pspt,s[i],spt);
            pspt=spt;
        }
        if(s[i]=='1'){
        pspt=pspt+1;
        printf("(%c,%c)->%c\n",pspt-1,s[i],pspt);
        if((pspt==pfpt))
        break;

    }
    }
    if(pspt==pfpt)
    printf("yes\n");
    else
     printf("no\n");



}
