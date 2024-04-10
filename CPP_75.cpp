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
};

void delete_node (Node* &head, int position) {

    if (position == 1) {

        Node *temp = head;
        head = head-> next;
        temp-> next = NULL;
        delete temp;

    } else {

        Node *temp = head;

        int count = 1;

        while (count < position-1) {

            temp = temp-> next;
            count++;
        }

        Node *current = temp-> next;
        temp-> next = current-> next;
        current-> next = NULL;
        delete current;
    }
}

void insert_at_head (Node* &head, int data) {

    Node *temp = new Node(data);

    temp-> next = head;
    head = temp;
}

void insert_at_tail (Node* &tail, int data) {

    Node *temp = new Node(data, NULL);

    tail-> next = temp;
    tail = temp;
}

void insert_at_position (Node* &head, Node*  &tail, int position, int data) {

    Node *temp = head;

    if (position == 1) {

        insert_at_head (head, data);
        return;
    }

    int count = 1;

    while (count < position-1) {

        temp = temp-> next;
        count++;
    }

    if (temp-> next == NULL) {

        insert_at_tail (tail, data);
        return;
    }

    Node *node_to_insert = new Node(data);

    node_to_insert-> next = temp-> next;
    temp-> next = node_to_insert;
}

void print (Node* &head) {

    Node *temp = head;

    while (temp != NULL) {

        cout << temp-> data << " ";
        temp = temp-> next;
    }

    cout << endl;
}


int main() {

    Node *linked_list = new Node(10, NULL);

    // linked_list -> next = NULL;

    Node *head = linked_list;
    Node *tail = linked_list;

    print (head);
    insert_at_head (head, 12); print (head);
    insert_at_head (head, 15); print (head);
    insert_at_head (head, 36); print (head);
    insert_at_head (head, 45); print (head);

    // print (tail);
    // insert_at_tail (tail, 12); print (head);
    // insert_at_tail (tail, 15); print (head);
    // insert_at_tail (tail, 36); print (head);

    delete_node (head, 3); print (head);

    return 0;
}