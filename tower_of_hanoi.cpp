#include<bits/stdc++.h>
using namespace std;
int c=1;
void tower_of_hanoi(int n,char from_rod,char to_rod,char aux_rod)
{
    if(n==0)
        return ;
    tower_of_hanoi(n-1,from_rod,aux_rod,to_rod);
    cout << c++ <<" Move disk " << n << "from disk " << from_rod << "to rod " << to_rod << endl;
    tower_of_hanoi(n-1,aux_rod,to_rod,from_rod);

}
int main()
{
    int disk;

    cout << "Enter the number of disk:";
    cin >> disk;
    tower_of_hanoi(disk,'A','C','D');
    return 0;
}
