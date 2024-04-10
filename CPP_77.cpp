#include<iostream>
using namespace std;

class Node {

    public:

    int data;
    Node *next;

    Node (int data) {

        this-> data = data;
    }

    Node (int data, Node *next) {

        this-> data = data;
        this-> next = next;
    }

    ~Node () {

        if (this-> next != NULL) {

            delete next;
            next = NULL;
        }
    }
};

void delete_node (Node* &tail, int element) {

    if (tail == NULL) {

        return;
    }

    Node *previous = tail;
    Node *current = previous-> next;

    if (previous == current) {

        tail = NULL;
        return;
    }

    while (current-> data != element) {

        previous = previous-> next;
        current = current-> next;
    }

    previous-> next = current-> next;

    if (tail == current) {

        tail = previous;
    }

    current-> next = NULL;
    delete current;
}

void insert_node (Node* &tail, int element, int data) {

    if (tail == NULL) {

        Node *temp = new Node (data);
        temp-> next = temp;
        tail = temp;

    } else {

        Node *current = tail;

        while (current-> data != element) {

            current = current-> next;
        }

        Node *temp = new Node (data);
        temp-> next = current-> next;
        current-> next = temp;
    }
}

void print (Node* &tail) {

    Node *temp = tail;

    do {

        cout << tail-> data << " ";
        tail = tail-> next;

    } while (tail != temp);

    cout << endl;
}

int main() {

    Node *tail = NULL;

    insert_node (tail, 10, 10); print (tail);
    insert_node (tail, 10, 20); print (tail);
    insert_node (tail, 20, 30); print (tail);
    insert_node (tail, 30, 40); print (tail);
    insert_node (tail, 40, 50); print (tail);

    return 0;
}