#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a priority queue of integers
    priority_queue<int> pq;

    // Insert elements into the priority queue
    pq.push(5);
    pq.push(2);
    pq.push(10);

    // Get the top element (highest priority)
    int top_elem = pq.top();
    cout << "Top element: " << top_elem << endl;

    // Remove the top element
    pq.pop();

    // Get the new top element
    top_elem = pq.top();
    cout << "New top element: " << top_elem << endl;

    return 0;
}
