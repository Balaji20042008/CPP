#include<iostream>
using namespace std;

class heap {

    public:

    int array[100];
    int size;

    heap () {

        array[0] = -1;
        size = 0;
    }

    void insert (int data) {

        size = size + 1;
        int index = size;
        array[index] = data;

        while (index > 1) {

            int parent = index/2;

            if (array[index] > array[parent]) {

                swap(array[index],array[parent]);
                index = parent;

            } else {

                return;
            }
        }
    }

    void print () {

        for (int i = 1; i <= size; i++) {

            cout << array[i] << " ";
        }

        cout << endl;
    }

    void deletion () {

        if (size == 0) {

            return;
        }

        array[1] = array[size];
        size--;

        for (int i = 1; i < size;) {

            int left_index = 2*i;
            int right_index = 2*i+1;

            if (left_index <= size && array[left_index] > array[i]) {

                swap(array[left_index],array[i]);

            } else if (right_index <= size && array[right_index] > array[i]) {

                swap(array[right_index],array[i]);

            } else {

                return;
            }
        }
    }
};

void heapify (int *array, int n, int i) {

    int largest_index = i;
    int left_index = 2*i;
    int right_index = 2*i+1;

    if (left_index <= n && array[largest_index] < array[left_index]) {

        largest_index = left_index; 
    }

    if (right_index <= n && array[largest_index] < array[right_index]) {

        largest_index = right_index;
    }

    if (largest_index != i) {

        swap(array[largest_index],array[i]);
        heapify(array,n,largest_index);
    }
}

void heap_sort (int *array, int n) {

    int size = n;

    while (size > 1) {

        swap(array[1],array[size]);
        size--;

        heapify(array,size,1);
    }
}

int main() {

    heap heap_max;

    heap_max.insert(60);
    heap_max.insert(50);
    heap_max.insert(40);
    heap_max.insert(30);
    heap_max.insert(20);
    heap_max.insert(70);

    cout << "Before Deletion: ";

    heap_max.print();

    heap_max.deletion();

    cout << "After Deletion: ";

    heap_max.print();

    int array[7] = {-1,60,50,40,30,20,70};
    int n = 6;

    cout << "Complete Binary Tree: ";

    for (int i = 1; i <= n; i++) {

        cout << array[i] << " ";
    }

    cout << endl;

    for (int i = n/2; i > 0; i--) {

        heapify(array,n,i);
    }

    cout << "Heap Tree: ";

    for (int i = 1; i <= n; i++) {

        cout << array[i] << " ";
    }

    cout << endl;

    heap_sort(array,n);

    cout << "Heap Sort: ";

    for (int i = 1; i <= n; i++) {

        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}