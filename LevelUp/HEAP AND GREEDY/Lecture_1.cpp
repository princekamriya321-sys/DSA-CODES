#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

public:

    // Insert element
    void insert(int val) {

        heap.push_back(val);

        int idx = heap.size() - 1;

        while (idx > 0) {

            int parent = (idx - 1) / 2;

            if (heap[parent] <= heap[idx])
                break;

            swap(heap[parent], heap[idx]);

            idx = parent;
        }
    }

    // Remove minimum element
    void remove() {

        if (heap.empty())
            return;

        heap[0] = heap.back();

        heap.pop_back();

        int idx = 0;

        while (true) {

            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            int smallest = idx;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;

            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == idx)
                break;

            swap(heap[idx], heap[smallest]);

            idx = smallest;
        }
    }

    int top() {

        if (heap.empty())
            return -1;

        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    void print() {

        for (int x : heap)
            cout << x << " ";

        cout << endl;
    }
};

int main() {

    MinHeap h;

    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(10);
    h.insert(50);

    h.print();      // 10 20 30 40 50 (array representation)

    cout << h.top() << endl;   // 10

    h.remove();

    h.print();      // 20 40 30 50
}