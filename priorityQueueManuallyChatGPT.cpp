#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& Q, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && Q[left] > Q[largest])
        largest = left;

    if (right < n && Q[right] > Q[largest])
        largest = right;

    if (largest != i) {
        swap(Q[i], Q[largest]);
        heapify(Q, n, largest);
    }
}

void build_heap(vector<int>& Q) {
    int n = Q.size();

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(Q, n, i);
}

int extract_max(vector<int>& Q) {
    int n = Q.size();

    if (n == 0) {
        cerr << "Heap underflow!" << endl;
        return -1;
    }

    int max_elem = Q[0];
    Q[0] = Q[n-1];
    Q.pop_back();

    heapify(Q, Q.size(), 0);

    return max_elem;
}

int extract_min(vector<int>& Q) {
    int n = Q.size();

    if (n == 0) {
        cerr << "Heap underflow!" << endl;
        return -1;
    }

    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (Q[i] < Q[min_index]) {
            min_index = i;
        }
    }

    int min_vertex = Q[min_index];
    Q[min_index] = Q[n-1];
    Q.pop_back();

    heapify(Q, Q.size(), min_index);

    return min_vertex;
}


void insert_elem(vector<int>& Q, int elem) {
    Q.push_back(elem);
    int i = Q.size() - 1;

    while (i > 0 && Q[(i-1)/2] < Q[i]) {
        swap(Q[i], Q[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    // Create a priority queue using a vector
    vector<int> pq = {5, 2, 10, 7, 1};

    // Build a max-heap from the vector
    build_heap(pq);

    // Get the maximum and minimum element (highest priority)
    int max_elem = extract_max(pq);
    int min_elem = extract_min(pq);

    cout << "Maximum element : " << max_elem << endl;
    cout << "Minimum element : " << min_elem << endl << endl;

    // Insert a new element into the priority queue
    insert_elem(pq, 8);
    insert_elem(pq, 0);

    // Get the maximum and minimum element again
    max_elem = extract_max(pq);
    min_elem = extract_min(pq);

    cout << "New maximum element: " << max_elem << endl;
    cout << "Minimum element : " << min_elem << endl << endl;

    return 0;
}
