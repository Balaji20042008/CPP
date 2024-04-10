#include<iostream>
using namespace std;

class Node {

    public:

    int data;
    Node *previous;
    Node *next;

    Node (int data) {

        this-> data = data;
    }

    Node (int data, Node *previous, Node *next) {

        this-> data = data;
        this-> previous = previous;
        this-> next = next;
    }
};

void delete_node (Node* &head, Node* &tail, int position) {

    if (position == 1) {

        Node *temp = head;
        head = head-> next;
        head-> previous = NULL;
        temp-> next = NULL;
        delete temp;
        return;
    }

    Node *current = head;
    Node *previous = NULL;
    int count = 1;

    while (count < position) {

        previous = current;
        current = current-> next;
        count++;
    }

    current-> previous = NULL;
    previous-> next = current-> next;

    if (current-> next == NULL) {

        tail = previous;
        delete current;

    } else {

        (current-> next)-> previous = current-> previous;
        current-> next = NULL;
        delete current;
    }
}

void print (Node* &head) {

    Node *temp = head;

    while (temp != NULL) {

        cout << temp-> data << " ";
        temp = temp-> next;
    }

    cout << endl;
}

int length (Node* &head) {

    Node *temp = head;

    int count = 0;

    while (temp != NULL) {

        count++;
        temp = temp-> next;
    }

    return count;
}

void insert_at_head (Node* &head, Node* &tail, int data) {

    if (head == NULL) {

        Node *temp = new Node (data, NULL, NULL);
        head = temp;
        tail = temp;

    } else {

        Node *temp = new Node (data, NULL, NULL);
        temp-> next = head;
        head-> previous = temp;
        head = temp;
    }
}

void insert_at_tail (Node* &head, Node* &tail, int data) {

    if (tail == NULL) {

        Node *temp = new Node (data, NULL, NULL);
        head = temp;
        tail = temp;

    } else {

        Node *temp = new Node (data, NULL, NULL);
        temp-> previous = tail;
        tail-> next = temp;
        tail = temp;
    }
}

void insert_at_position (Node* &head, Node* &tail, int position , int data) {

    if (position == 1) {

        insert_at_head (head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position-1) {

        temp = temp-> next;
        count++;
    }

    if (temp-> next == NULL) {

        insert_at_tail (head, tail, data);
        return;
    }

    Node *node_to_insert = new Node (data, NULL, NULL);
    node_to_insert-> next = temp-> next;
    (temp-> next)-> previous = node_to_insert;
    temp-> next = node_to_insert;
    node_to_insert-> previous = temp;
}

int main() {

    Node *linked_list = new Node (10, NULL, NULL);

    // cout << "The address of the previous node is: " << linked_list-> previous << endl;
    // cout << "The data in the current node is: " << linked_list-> data << endl;
    // cout << "The address of the next node is: " << linked_list-> next << endl;

    Node *head = linked_list;
    Node *tail = linked_list;

    // cout << "The length of te linked list is: " << length(head) << endl;

    // print (head);
    // insert_at_head (head, tail, 12); print (head);
    // insert_at_head (head, tail, 15); print (head);
    // insert_at_head (head, tail, 36); print (head);

    print (head);
    insert_at_tail (head, tail, 12); print (head);
    insert_at_tail (head, tail, 15); print (head);
    insert_at_tail (head, tail, 36); print (head);

    // insert_at_position (head, tail, 3, 25); print (head);

    delete_node (head, tail, 1); print (head);

    cout << "head: " << head-> data << endl;
    cout << "tail: " << tail-> data << endl;

    return 0;
}
