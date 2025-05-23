// heap.cpp
// Luis Bernuy
#include <algorithm>
#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value) {
    vdata.push_back(value);
    int idx = vdata.size() - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (vdata[idx] < vdata[parent]) {
            std::swap(vdata[idx], vdata[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop() {
    if (vdata.empty()) return;
    vdata[0] = vdata.back();
    vdata.pop_back();
    int idx = 0, n = vdata.size();
    while (true) {
        int left  = 2*idx + 1;
        int right = 2*idx + 2;
        int smallest = idx;

        if (left < n && vdata[left] < vdata[smallest]) {
            smallest = left;
        }
        if (right < n && vdata[right] < vdata[smallest]) {
            smallest = right;
        }
        if (smallest != idx) {
            std::swap(vdata[idx], vdata[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }
}

// Returns the minimum element in the heap
int Heap::top() {
    if (vdata.empty()) {
        cout << "Heap is empty!\n";
        return -1;  // or throw, depending on your error policy
    }
    return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty() {
    return vdata.empty();
}
    