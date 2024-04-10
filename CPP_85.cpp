#include<iostream>
#include<queue>
using namespace std;

class node {

    public:

    int data;
    node* left;
    node* right;

    node (int d) {

        this-> data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
};

node* tree (node* root) {

    cout << "Data: ";

    int data;
    cin >> data;

    root = new node(data);

    if (data == -1) {

        return NULL;
    }

    cout << "Inserting node in the left of " << data << endl;
    root-> left = tree (root-> left);

    cout << "Inserting node in the right of " << data << endl;
    root-> right = tree (root-> right);

    return root;
}

void level_order (node* root) {

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        node* temp = q.front();
        q.pop();

        if (temp == NULL) {

            cout << endl;

            if (!q.empty()) {

                q.push(NULL);
            }
        }

        else {

            cout << temp-> data << " ";

            if (temp-> left != NULL) {

                q.push(temp-> left);
            }

            if (temp-> right != NULL) {

                q.push(temp-> right);
            }
        }
    }
}

void inorder (node* root) {

    if (root == NULL) {

        return;
    }

    inorder (root-> left);
    cout << root-> data << " ";
    inorder (root-> right);
}

void preorder (node* root) {

    if (root == NULL) {

        return;
    }

    cout << root-> data << " ";
    preorder(root-> left);
    preorder(root-> right);
}

void postorder (node* root) {

    if (root == NULL) {

        return;
    }

    postorder(root-> left);
    postorder(root-> right);
    cout << root-> data << " ";
}

void build_from_levelorder (node* &root) {

    cout << "Data: ";

    queue <node*> q;

    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty()) {

        node* temp = q.front();
        q.pop();

        cout << "Left Node To " << temp-> data << ": ";

        int left_data;
        cin >> left_data;

        if (left_data != -1) {

            temp-> left = new node(left_data);
            q.push(temp-> left);
        }

        cout << "Right Node To " << temp-> data << ": ";

        int right_data;
        cin >> right_data;

        if (right_data != -1) {

            temp-> right = new node(right_data);
            q.push(temp-> right);
        }
    }

    // queue <node*> q;

    // cout << "Data: ";

    // int data;
    // cin >> data;

    // root = new node(data);
    // q.push(root);

    // while(!q.empty()) {

    //     node *temp = q.front();
    //     q.pop();

    //     cout << "Left Node To " << temp-> data << endl;

    //     int left_data;
    //     cin >> left_data;

    //     if (left_data != -1) {

    //         temp-> left = new node(left_data);
    //         q.push(temp-> left);
    //     }

    //     cout << "Right Node To " << temp-> data << endl;

    //     int right_data;
    //     cin >> right_data;

    //     if (right_data != -1) {

    //         temp-> right = new node(right_data);
    //         q.push(temp-> right);
    //     }
    // }

}
 
int main() {

    node* root = NULL;

    // build_from_levelorder(root);
    // level_order(root);

    root = tree(root);

    // cout << endl;

    // cout << "Level Order Traversal" << endl;
    // level_order(root);

    // cout << "Inorder Traversal" << endl;
    // inorder(root);
    // cout << endl;

    // cout << "Preorder traversal" << endl;
    // preorder(root);
    // cout << endl;

    // cout << "Postorder Traversal" << endl;
    // postorder(root);
    // cout << endl;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    return 0;
}