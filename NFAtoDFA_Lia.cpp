#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    string states[5];
    printf("States :\n");
    for (int i = 0; i < 4; i++)
    {
        cin>>states[i];
    }

    printf("Starting state :\n");
    string starting_state;
    cin>>starting_state;
    printf("Ending state :\n");
    string Ending_state;
    cin>>Ending_state;
    string queue[100];int j=0;int s=0;

   

    char str[100];
    printf("String : \n");
    scanf("%s",str);
    getchar();
    
    int isDestination=0;

   for(int i=0;i<strlen(str);i++)
   {   
     queue[j++]=states[s];

      if(str[i]=='1')
      {  
          if(str[i+1]=='1' && str[i+2]=='1')
          {
             queue[j++]=states[s+1];
             queue[j++]=states[s+2];
             queue[j++]=states[s+3];

             i+=2;
             
             if(queue[j-1]==Ending_state)
             isDestination=1;

             while (i!=strlen(str)-1)
             {
                queue[j]=states[s+3];
                j++;
                i++;
             }
             

          }
      }
      
   }

   if(isDestination)
   printf("Accedpted in NFA !!!\n");
   isDestination=0;
   cout<<"NFA Path - \t";
   for(int i=0;i<j;i++)
    {cout<<queue[i];}
    cout<<"\n";
   states[4]="E";
   vector<string> Dfa_states;
   string CurrentState=starting_state;
   
   for(int i=0;i<strlen(str);i++)
   {
     if(CurrentState==states[0])
     {
        if(str[i]=='1')
        CurrentState=states[0]+states[1];
     }
    else if(CurrentState==states[1])
     {
        if(str[i]=='1')
        CurrentState=states[2];
        else if(str[i]=='0')
        CurrentState=states[4];
     }
     else if(CurrentState==states[2])
     {
        if(str[i]=='1')
        CurrentState=states[3];
        else if(str[i]=='0')
        CurrentState=states[4];
     }
     else if(CurrentState==states[3])
     {
        if(str[i]=='1')
        CurrentState=states[3];
        else if(str[i]=='0')
        CurrentState=states[3];
     }
     else if(CurrentState==states[4])
     {
        if(str[i]=='1')
        CurrentState=states[4];
        else if(str[i]=='0')
        CurrentState=states[4];
     }
     else if(CurrentState==states[0]+states[1])
     {
        if(str[i]=='1')
        CurrentState=states[0]+states[1]+states[2];
        else if(str[i]=='0')
        CurrentState=states[0];
     }
     else if(CurrentState==states[0]+states[1]+states[2])
     {
        if(str[i]=='1')
        CurrentState=states[0]+states[1]+states[2]+states[3];
        else if(str[i]=='0')
        CurrentState=states[0];
     }
     else if(CurrentState==states[0]+states[1]+states[2]+states[3])
     {
        if(str[i]=='1')
        CurrentState=states[0]+states[1]+states[2]+states[3];
        else if(str[i]=='0')
        CurrentState=states[0]+states[3];
     }
     else if(CurrentState==states[0]+states[3])
     {
        if(str[i]=='1')
        CurrentState=states[0]+states[1]+states[3];
        else if(str[i]=='0')
        CurrentState=states[0]+states[3];
     }
     else if(CurrentState==states[0]+states[1]+states[3])
     {
        if(str[i]=='1')
        CurrentState=states[0]+states[1]+states[3];
        else if(str[i]=='0')
        CurrentState=states[0]+states[3];
     }
     Dfa_states.push_back(CurrentState);
     Dfa_states.push_back(" ");
     if(CurrentState==states[0]+states[1]+states[3]||CurrentState==states[0]+states[3]|| CurrentState==states[0]+states[1]+states[2]+states[3] || CurrentState==states[3])
     {
        isDestination=1;
     }
   }
  

   if(isDestination)
   printf("Accedpted in DFA !!!\n");
   
   cout<<"DFA Path - \t";
   for(int i=0;i<Dfa_states.size();i++)
   {
      cout<<Dfa_states[i];
   }
}