#include<iostream>
#include<string>
using namespace std;
int main()
{
int table[3][2] = {{2, 1}, {1, 1}, {2, 2}};
string input;
int state = 0;
cout<<"Program that accepts strings starting with 1:\nEnter String: ";
cin>>input;
cout<<input<<endl;
cout<<"Transitions: \n";
for(int i = 0; i < input.length(); i++)
{
cout<<"(q"<<state<<", "<<input[i]<<") -> q";
state = table[state][input[i] - '0'];
cout<<state<<endl;
}
if(state == 1)
cout<<"\nString accepted!";
else
cout<<"\nNot accepted!";
return 0;
}