#include <bits/stdc++.h>
#define MAX 100
using namespace std;

struct works {
    string descrpt;
    int start;
    int finish;
}activities[MAX];

int n, i, j, k = 0, cnt = 1;

int main ()
{
    cout << "Input the number of activities Moumita has to perform today : ";
    cin >> n;

    cout << "Enter the activities description, starting and finishing time :\n\n";

    for (i = 0; i < n; i++){
        cin >> activities[i].descrpt;
        cin >> activities[i].start;
        cin >> activities[i].finish;
    }
    cout << endl;

    //sorting by structure
    struct works temp;

    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){

            if (activities[i].finish > activities[j].finish){
               temp = activities[i];
               activities[i] = activities[j];
               activities[j] = temp;
            }
        }
    }

    struct works output[MAX];

    for (i=0; i<n; i++){
        for (j=i+1; j<n; j++){

            if  (activities[i].finish <= activities[j].start){
                output[k] = activities[i];
                k++;
                output[k] = activities[j];

                cnt++;
                i = j - 1;
                break;
            }
        }
    }

    cout << "\nMaximum number of activities she can perform today : " << cnt << endl;

    for (k = 0; k < cnt; k++){
        cout << output[k].descrpt << endl;
    }

    return 0;
}