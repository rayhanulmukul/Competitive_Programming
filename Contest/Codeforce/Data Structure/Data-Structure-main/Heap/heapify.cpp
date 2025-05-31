#include <iostream>

using namespace std;

void heapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left < n && heap[largest] < heap[left]) {
        largest = left;
    }
    if(right < n && heap[largest] < heap[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(heap[largest], heap[i]);
        heapify(heap, n, largest);
    }
    else {
        return ;
    }
}

int main() {
    int size = 7;
    int heap[size] = {-1, 76, 89, 9, 34, 56, 78};

    for(int i = size / 2; i > 0; i--) {
        heapify(heap, size, i);
    }

    for(int i = 1; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;

}
