#include <iostream>

using namespace std;

class Heap {
public:
    int heap[100];
    int size = 0;

    Heap() {
        heap[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        heap[index] = val;
        
        while(index > 1) {
            int parent = index / 2;
            if(heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void delete_root() {
        if(size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[1] = heap[size];
        size = size-1;

        int i = 1;
        while(i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex < size && heap[i]  < heap[leftIndex]) {
                swap(heap[i], heap[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && heap[i] < heap[rightIndex]) {
                swap(heap[i], heap[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }

    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap;
    heap.insert(125);
    heap.insert(165);
    heap.insert(45);
    heap.insert(65);
    heap.insert(155);

    heap.print();

    heap.delete_root();
    heap.print();

    return 0;
}
