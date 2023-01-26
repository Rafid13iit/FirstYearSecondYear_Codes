#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN 100

int main()
{
    int states, count = 0;
	char start, final;
	string str;

	printf("How many states?\n");
	scanf("%d", &states);

	printf("Let, starting state is : A\n");
	start = 'A';
 
	printf("Your states are :\n");
	for (char x = start; x < start + states; x++){
		printf("%c ", x);
		final = x;
	}

	printf("\nLet, final state is : %c\n", final);

	printf("Input a bit string : ");
	scanf("%s", str);

	int i = 0, temp = 0;
    char state = start;

    printf("One possible path is :\n");

    for (int i = 0; i < strlen(str); i++) {

        if (str[i] == '1' && str[i+1] == '1' && str[i+2] == '1' && count == 0) {
            if (state == start) {
                state += 1;
                printf("(%c,1) -> %c\n", state-1 , state);
            } 
            if (state == start+1) {
                state += 1;
                printf("(%c,1) -> %c\n", state-1 , state);
            } 
            if (state == start+2) {
                state += 1;
                printf("(%c,1) -> %c\n", state-1 , state);
            }
            
            i += 2;
            count++;
        } 
        
        else {
            printf("(%c,%c) -> %c\n", state , str[i], state);
        }
    }

    if (state != final){
        printf("NOT ACCEPTED, as NFA can not reach it's final state, so string does not contain 111 as substring.\n");
        printf("Can not find DFA of the NFA that has 111 as substring!\n\n");
    	return 0;
    }

	printf("ACCEPTED, string contains 111 as substring.\n\n");

    state = start;

	printf("Transition table for the NFA is:\n\n");

    //printf("|%10s|%10s|","0","1");
    //printf("\n");

    for (state = start; state <= final; state++){
        if (state == start + 0){
            printf("{%c, 0}   ->   {%c}\n", state, state);
            printf("{%c, 1}   ->   {%c, %c}\n", state, state, state+1);
        }

        else if (state == start + 1){
            printf("{%c, 0}   ->   Blank\n", state);
            printf("{%c, 1}   ->   {%c}\n", state, state+1);
        }

        else if (state == start + 2){
            printf("{%c, 0}   ->   Blank\n", state);
            printf("{%c, 1}   ->   {%c}\n", state, state+1);
        }
        else if (state == start + 3){
            printf("{%c, 0}   ->   {%c}\n", state, state);
            printf("{%c, 1}   ->   {%c}\n", state, state);
        }
    }

    //start of DFA conversion
    //assume we have a 2-dimensional array named 'transition' to store the transition table
    char transition[states][2];
    char DFA_start = 'A';
    //char DFA_final = 'D';
    string CurrentState;
    CurrentState = DFA_start;

    state = DFA_start;

    for(int i=0;i<strlen(str);i++)
   {
     if(CurrentState == state)
     {
        if(str[i]=='1')
        CurrentState = state + (state+1);
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

    
    return 0;
}
