#include<iostream>
#include<queue>
using namespace std;

class node {

    public:

    int data;
    node *left;
    node *right;

    node (int data) {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void level_order (node *root) {

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        node *front = q.front();
        q.pop();

        if (front == NULL) {

            cout << endl;

            if (!q.empty()) {

                q.push(NULL);
            }

        } else {

            cout << front->data << " ";

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }
    }
}

void inorder (node *root) {

    if (root == NULL) {

        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder (node *root) {

    if (root == NULL) {

        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder (node *root) {

    if (root == NULL) {

        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

node* minimum (node *root) {

    // if (root->left == NULL) {

    //     return root;

    // } else {

    //     return minimum(root->left);
    // }

    node *temp = root->left;

    while (temp->left != NULL) {

        temp = temp->left;
    }

    return temp;
}

node* maximum (node *root) {

    // if (root->right == NULL) {

    //     return root;

    // } else {

    //     return maximum(root->right);
    // }

    node *temp = root->right;

    while (temp->right != NULL) {

        temp = temp->right;
    }

    return temp;
}

node* delete_from_bst (node *root, int value) {

    if (root == NULL) {

        return NULL;
    }

    if (root->data == value) {

        if (root->left == NULL && root->right == NULL) {

            delete root;
            return NULL;

        } else if (root->left != NULL && root->right == NULL) {

            node *temp = root->left;
            delete root;
            return temp;

        } else if (root->left == NULL && root->right != NULL) {

            node *temp = root->right;
            delete root;
            return temp;

        } else {

            int min = minimum(root->right)->data;
            root->data = min;
            root->right = delete_from_bst(root->right,min);
            return root;
        }


    } else if (root->data > value) {

        root->left = delete_from_bst(root->left,value);
        return root;

    } else {

        root->right = delete_from_bst(root->right,value);
        return root;
    }


}

node* insert_into_bst (node* root, int data) {

    if (root == NULL) {

        root = new node(data);
        return root;
    }

    if (root->data > data) {

        root->left = insert_into_bst(root->left,data);

    } else {

        root->right = insert_into_bst(root->right,data);
    }

    return root;
}

void take_input (node* &root) {

    int data;
    cin >> data;

    while (data != -1) {

        root = insert_into_bst(root,data);
        cin >> data;
    }
}

void predecessor_and_successor (node *root, node *&predecessor, node *&successor, int key) {

    if (root == NULL) {

        return;
    }

    if (root->data == key) {

        if (root->left != NULL) {

            node *temp = root->left;

            while (temp->right != NULL) {

                temp = temp->right;
            }

            predecessor = temp;
        }

        if (root->right != NULL) {

            node *temp = root->right;

            while (temp->left != NULL) {

                temp = temp->left;
            }

            successor = temp;
        }

        return;

    }
    
    if (root->data > key) {

        successor = root;
        predecessor_and_successor(root->left,predecessor,successor,key);

    } else {

        predecessor = root;
        predecessor_and_successor(root->right,predecessor,successor,key);
    }
}

int main() {

    node *root = NULL;

    // 50 20 70 10 30 90 100 -1

    cout << "Data: ";
    take_input(root);

    // cout << endl;
    
    cout << "Level Order Traversal: " << endl;
    level_order(root);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    // cout << endl;

    // cout << "Minimum value in the BST: " << minimum(root)->data << endl;
    // cout << "Maximum value in the BST: " << maximum(root)->data << endl;

    // root = delete_from_bst(root,50);

    // cout << "Level Order Traversal: " << endl;
    // level_order(root);

    // cout << "Inorder Traversal: ";
    // inorder(root);
    // cout << endl;

    // cout << "Preorder Traversal: ";
    // preorder(root);
    // cout << endl;

    // cout << "Postorder Traversal: ";
    // postorder(root);
    // cout << endl;

    int key = 50;

    node *predecessor = NULL;
    node *successor = NULL;

    predecessor_and_successor(root,predecessor,successor,key);

    cout << "The inorder predecessor for " << key << " is: " << predecessor->data << endl;
    cout << "The inorder successor for " << key << " is: " << successor->data << endl;

    key = 70;

    predecessor_and_successor(root,predecessor,successor,key);

    cout << "The inorder predecessor for " << key << " is: " << predecessor->data << endl;
    cout << "The inorder successor for " << key << " is: " << successor->data << endl;

    return 0;
}