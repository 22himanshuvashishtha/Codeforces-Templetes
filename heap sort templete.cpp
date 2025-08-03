#include <bits/stdc++.h>
using namespace std;

class mheap {
    vector<int> heap;

    void heapify_down(int ind, int n) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int value = heap[ind];
        int greater = ind;

        if (left < n && heap[left] > value) {
            value = heap[left];
            greater = left;
        }
        if (right < n && heap[right] > value) {
            value = heap[right];
            greater = right;
        }
        if (greater == ind) return;

        swap(heap[ind], heap[greater]);
        heapify_down(greater, n);
    }

public:
    mheap(vector<int> v) {
        heap = v;
    }

    void build_head() {
        int n = heap.size();
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify_down(i, n);
        }
    }

    void heap_sort() {
        build_head();
        int n = heap.size();
        for (int i = n - 1; i > 0; i--) {
            swap(heap[0], heap[i]);         
            heapify_down(0, i);             
        }
    }

    void print_sorted() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

void solve() {
    int t;
    cin >> t;
    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }
    mheap hp(v);
    hp.heap_sort();
    hp.print_sorted();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
