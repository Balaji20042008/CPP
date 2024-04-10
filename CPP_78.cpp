#include<iostream>
#include<map>
using namespace std;

class Node {

    public:

    int data;
    Node *next;

    Node (int data) {

        this-> data = data;
        this-> next = NULL;
    }

    Node (int data, Node* &next) {

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

    Node *temp = new Node(data);

    tail-> next = temp;
    tail = temp;
}

void insert_at_position (Node* head, Node* tail, int position, int data) {


    Node *temp = head;

    if (position == 1) {

        insert_at_head (temp, data);
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

        cout << temp-> data << " ",
        temp = temp-> next;
    }

    cout << endl;
}

int length (Node *head) {

    Node *temp = head;

    int count = 0;

    while (temp != NULL) {

        temp = temp-> next;
        count++;
    }

    return count;
}

Node *kReverse (Node* head, int k) {

    if (head == NULL) {

        return NULL;
    }

    int l = length (head);

    int count = 0;

    Node *next = NULL;
    Node *previous = NULL;
    Node *current = head;

    while (current-> next != NULL && count < k) {

        if (k > l) {

            return head;
        }

        next = current-> next;
        current-> next = previous;
        previous = current;
        current = next;
        count++;
    }

    if (current != NULL) {

        head-> next = kReverse (next, k); 
    }

    return previous;
}

bool detect_cycle (Node *head) {

    if (head == NULL) {

        return 0;
    }

    Node *temp = head;
    map <Node*,bool> visited;

    while (temp != NULL) {

        if (visited[temp] == true) {

            return 1;
        }

        visited[temp] = true;
        temp = temp-> next;
    }

    return 0;
}

Node* flyod_cycle (Node *head) {

    if (head == NULL) {

        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL) {

        fast = fast-> next;

        if (fast != NULL) {

            fast = fast-> next;
        }

        slow = slow-> next;

        if (slow == fast) {

            slow = head;

            while (slow != fast) {

                slow = slow-> next;
                fast = fast-> next;
            }

            return slow;
        }
    }

    return NULL;
}

void remove_loop (Node *head) {

    if (head == NULL) {

        return;
    }

    Node *start = flyod_cycle(head);
    Node *end = start;

    while (end-> next != start) {

        end = end-> next;
    }

    end-> next = NULL;
}

int main() {

    Node *linked_list = new Node(10);

    Node *head = linked_list;
    Node *tail = linked_list;

    print(head);
    insert_at_tail (tail, 20); print (head);
    insert_at_tail (tail, 30); print (head);
    insert_at_tail (tail, 40); print (head);
    insert_at_tail (tail, 50); print (head);
    insert_at_tail (tail, 60); print (head);

    tail-> next = (head-> next)-> next;

    if (flyod_cycle(head) != NULL) {

        cout << "The loop is present in the given linked list." << endl;
        cout << "The beginning node of the loop is " << flyod_cycle(head)-> data << "." << endl;

        remove_loop (head);

        cout << "The loop is removed from the linked list." << endl;
        print (head);
         
    } else {

        cout << "The loop is absent in the given linked list." << endl;
    }
 
    return 0;
}