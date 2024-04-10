#include<iostream>
#include<queue>
using namespace std;

class Circular_Queue {

    public:

    int *array;
    int front;
    int rear;
    int size;

    Circular_Queue (int size) {

        array = new int[size];
        this-> size = size;
        front = -1;
        rear = -1;
    }

    bool enqueue (int x) {

        if ((front == 0 && rear == size-1) || (rear == (front-1) % (size-1))) {

            return false;

        } else if (front == -1) {

            front = 0;
            rear = 0;

        } else if (rear == size-1 && front != 0) {

            rear = 0;

        } else {

            rear++;
        }

        array[rear] = x;
        return true;
    }

    int dequeue () {

        if (front == -1) {

            return -1;
        }

        int ans = array[front];
        array[front] = -1;

        if (front == rear) {

            front = -1;
            rear = -1;

        } else if (front == size-1) {

            front = 0;

        } else {

            front++;
        }

        return ans;
    }
};

int main() {

    Circular_Queue queue(10);

    return 0;
}