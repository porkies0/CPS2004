#include <iostream>

using namespace std;

class Heap {
    private:
        int* data;
        int size;
        int capacity;

    public:
        Heap(int cap) : size(0), capacity(cap) {
            data = new int[capacity];
        }

        ~Heap() {
            delete[] data;
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "Heap is full!" << endl;
                return;
            }
            data[size] = value;
            size++;
            heapifyUp(size - 1);
        }

        void heapifyUp(int index) {
            while (index > 0) {
                int parentIndex = (index - 1) / 2;
                if (data[index] > data[parentIndex]) {
                    swap(data[index], data[parentIndex]);
                    index = parentIndex;
                } else {
                    break;
                }
            }
        }

        void printHeap() {
            for (int i = 0; i < size; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
};