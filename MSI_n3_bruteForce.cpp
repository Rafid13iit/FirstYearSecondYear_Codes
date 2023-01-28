#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
                startIndex = i;
                endIndex = j;
            }

            cout << "Sum: " << sum << endl;
            cout << "Interval: [" << i << ", " << j << "]" << endl << endl;
        }
    }

    cout << endl << "Maximum sum: " << maxSum << endl;
    cout << "Interval: [" << startIndex << ", " << endIndex << "]" << endl;
    return 0;
}
