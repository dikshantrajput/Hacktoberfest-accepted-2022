#include <bits/stdc++.h>
using namespace std;

#define parent(a) (floor(((a)-1)/2))
#define leftChild(a) (2*(a)+1)
#define rightChild(a) (2*(a)+2)

void heapifyMin(vector<int> &heap, int index) {
    int n = heap.size();
    int l = leftChild(index);
    int r = rightChild(index);
    int smallest = index;
    if(l < n && heap[l] < heap[index]) smallest = l;
    if(r < n && heap[r] < heap[smallest]) smallest = r;
    if(smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyMin(heap, smallest);
    }
}

void heapifyMin2(vector<int> &heap, int index) {
    int n = heap.size();
    int p = parent(index);
    if(index > 0 && heap[p] > heap[index]) {
        swap(heap[p], heap[index]);
        heapifyMin2(heap, p);
    }
}

void heapifyMax(vector<int> &heap, int index) {
    int n = heap.size();
    int l = leftChild(index);
    int r = rightChild(index);
    int largest = index;
    if(l < n && heap[l] > heap[index]) largest = l;
    if(r < n && heap[r] > heap[largest]) largest = r;
    if(largest != index) {
        swap(heap[largest], heap[index]);
        heapifyMax(heap, largest);
    }
}

void heapifyMax2(vector<int> &heap,  int index) {
    int n = heap.size();
    int p = parent(index);
    if(index > 0 && heap[p] < heap[index]) {
        swap(heap[p], heap[index]);
        heapifyMax2(heap, p);
    }
}

void heapify(vector<int> &heap, int index, bool isMinHeap = true) {
    if(isMinHeap) heapifyMin(heap, index);
    else heapifyMax(heap, index);
}

void heapifyHeap(vector<int> &heap, bool isMinHeap = true) {
    for(int i = heap.size()-1; i >= 0; i--) heapify(heap, i, isMinHeap);
}

void inputHeap(vector<int> &heap, bool isMinHeap = true) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        heap.push_back(tmp);
    }
    heapifyHeap(heap, isMinHeap);
}

void insertIntoHeap(vector<int> &heap, int element, bool isMinHeap = true) {
    heap.push_back(element);
    if(isMinHeap) heapifyMin2(heap, heap.size()-1);
    else heapifyMax2(heap, heap.size()-1);
}

void deleteFromHeap(vector<int> &heap, int element, bool isMinHeap = true) {
    int index = -1;
    for(int i = 0; i < heap.size(); i++) {
        if(heap[i] == element) {
            index = i;
            break;
        }
    }
    swap(heap[index], heap[heap.size()-1]);
    heap.pop_back();
    if(isMinHeap) heapifyMin(heap, index);
    else heapifyMax(heap, index);
}

void printHeap(vector<int> &heap) {
    for(int i = 0; i < heap.size(); i++) cout << heap[i] << " ";
    cout << endl;
}
