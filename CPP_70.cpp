#include<iostream>
using namespace std;

void merge (int *array, int start, int end) {

    int mid = start + (end-start) / 2;

    int length_01 = mid - start - 1;
    int length_02 = end - mid;

    int *first = new int[length_01];
    int *second = new int[length_02];

    int k = start;

    for (int i = 0; i < length_01; i++) {

        first[i] = array[k++];
    }

    k = mid + 1;

    for (int i = 0; i < length_02; i++) {

        second[i] = array[k++];
    }

    int index_01 = 0;
    int index_02 = 0;
    k = start;

    while (index_01 < length_01 && index_02 < length_02) {

        if (first[index_01] < second[index_02]) {

            array[k++] = first[index_01++];

        } else {

            array[k++] = second[index_02++];
        }
    }

    while (index_01 < length_01) {

        array[k++] = first[index_01++];
    }

    while (index_02 < length_02) {

        array[k++] = second[index_02++];
    }
}

void merge_sort (int *array, int start, int end) {

    if (start >= end) {

        return;
    }

    int mid = start + (end-start) / 2;

    merge_sort (array, start, mid);

    merge_sort (array, mid + 1, end);

    merge (array, start, end);
}

int main() {

    int array[5] = {25, 90, 12, 60, 45};

    merge_sort (array, 0, 4);

    cout << "Array: ";

    for (int i = 0; i < 5; i++) {

        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}