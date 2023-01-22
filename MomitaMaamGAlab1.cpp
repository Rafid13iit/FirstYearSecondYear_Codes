#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
struct activity{
    string description;
    int starting_time;
    int finishing_time;
};

bool comp (activity i,activity j) {
    return (i.finishing_time<j.finishing_time);
}

int main()
{
    int number_of_activities;
    cin>>number_of_activities;
    vector<activity> activities;
   
    activity temp;
    for(int i=0; i<number_of_activities;i++)
    {
        cin>>temp.description>>temp.starting_time>>temp.finishing_time;
        activities.push_back(temp);
    }
    sort(activities.begin(), activities.end(), comp);
   
   
   
    return 0;
}