#include<iostream>
#include<queue>
using namespace std;

class Queue {

    public:

    int *array;
    int front;
    int rear;
    int size;

    Queue (int size) {

        array = new int[size];
        this-> size = size;
        front = 0;
        rear = 0;
    }

    bool empty () {

        if (front == rear) {

            return true;

        } else {

            return false;
        }
    }

    void enqueue (int x) {

        if (rear == size) {

            return;

        } else {

            array[rear] = x;
            rear++;
        }
    }

    int dequeue () {

        if (front == rear) {

            return -1;

        } else {

            int ans = array[front];

            array[front] = -1;
            front++;

            if (front == rear) {

                front = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int first () {

        if (front == rear) {

            return -1;

        } else {

            return array[front];
        }
    }

    int length () {

        return rear - front;
    }

    int last () {

        if (front == rear) {

            return -1;

        } else {

            return array[rear-1];
        }
    }
};

int main() {

    Queue queue(10);

    // queue.enqueue(10);
    // queue.enqueue(20);
    // queue.enqueue(30);
    // queue.enqueue(40);
    // queue.enqueue(50);
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.dequeue();
    // queue.enqueue(60);
    // queue.enqueue(70);
    // queue.enqueue(80);
    // queue.enqueue(90);
    // queue.enqueue(100);
    // queue.enqueue(110);

    cout << "The size of the queue is: " << queue.length() << endl;
    cout << "The first element in the queue is: " << queue.first() << endl;
    cout << "The last element in the queue is: " << queue.last() << endl;
    
    if (queue.empty()) {

        cout << "The queue is empty" << endl;

    } else {

        cout << "The queue is not empty" << endl;
    }

    return 0;
}