#include<iostream>
#include<queue>
#include<vector>
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

node* tree (node *root) {

    cout << "Data: ";

    int data;
    cin >> data;

    root = new node(data);

    if (data == -1) {

        return NULL;
    }

    cout << "Inserting node in the left of " << data << endl;
    root->left = tree(root->left);

    cout << "Inserting node in the right of " << data << endl;
    root->right = tree(root->right);

    return root;
}

void level_order (node *root) {

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        node *front = q.front();
        q.pop();

        if (front == NULL) {

            cout << endl;

            if (!q.empty()) {

                q.push(NULL);

            } 

        } else {

            cout << front->data << " ";

            if (front->left != NULL) {

                q.push(front->left);
            }

            if (front->right != NULL) {

                q.push(front->right);
            }
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

vector<int> zigzag_traversal (node *root) {

    vector<int> result;

    if (root == NULL)
        return result;

    queue<node*> q;
    q.push(root);

    bool flag = true;

    while (!q.empty()) {

        int size = q.size();
        vector<int> answer(size);

        for (int i = 0; i < size; i++) {

            node *front = q.front();
            q.pop();

            int index = flag ? i : size - i - 1;
            answer[index] = front->data;

            if (front->left != NULL)
                q.push(front->left);

            if(front->right != NULL)
                q.push(front->right);
        }

        flag = !flag;

        for (int i = 0; i < size; i++) {

            result.push_back(answer[i]);
        }
    }

    return result;
}

void morris_traversal (node *root) {

    node *current = root;
    node *predecessor;

    while (current != NULL) {

        if (current->left == NULL) {

            cout << current->data << " ";
            current = current->right;

        } else {

            predecessor = current->left;

            while (predecessor->right != NULL && predecessor->right != current) {

                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {

                predecessor->right = current;
                current = current->left;

            } else {

                predecessor->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

void transverse_left (node *root, vector<int> &result) {

    if (root == NULL || (root->right == NULL && root->left == NULL)) {

        return;
    }

    result.push_back(root->data);

    if (root->left != NULL) {

        transverse_left (root->left, result);

    } else {

        transverse_left (root->right, result);
    }
}

void transverse_leaf (node *root, vector<int> &result) {

    if (root == NULL) {

        return;
    }

    if (root->left == NULL && root->right == NULL) {

        result.push_back(root->data);
        return;
    }

    transverse_leaf (root->left, result);
    transverse_leaf (root->right, result);
}

void transverse_right (node *root, vector<int> &result) {

    if (root == NULL || (root->left == NULL && root->right == NULL)) {

        return;
    }

    if (root->right != NULL) {

        transverse_right (root->left, result);

    } else {

        transverse_right (root->right, result);
    }

    result.push_back(root->data);
}

vector<int> boundary_traversal (node *root) {

    vector<int> result;

    if (root == NULL) {

        return result;
    }

    result.push_back(root->data);

    transverse_left (root->left, result);

    transverse_leaf (root->left, result);
    transverse_leaf (root->right, result);

    transverse_right (root->right, result);

    return result;
}

int height (node *root) {

    if (root == NULL) {

        return 0;
    }

    int height_01 = height(root->left);
    int height_02 = height(root->right);

    int answer = max(height_01,height_02) + 1;

    return answer;
}

pair<int,int> diameter_and_height (node *root) {

    pair<int,int> answer;

    if (root == NULL) {

        pair<int,int> p  = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameter_and_height(root->left);
    pair<int,int> right = diameter_and_height(root->right);

    int diameter_01 = left.first;
    int diameter_02 = right.first;
    int diameter_03 = left.second + right.second + 1;

    answer.first = max (diameter_01, max (diameter_02, diameter_03));
    answer.second = max (left.second, right.second) + 1;

    return answer;
}

int main() {

    node *root;

    root = tree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << endl;

    cout << "The height of the binary tree is: " << diameter_and_height(root).second << endl;
    cout << "The diameter of the binary tree is: " << diameter_and_height(root).first << endl;

    cout << "Zig-Zag Traversal: ";

    vector<int> zigzag = zigzag_traversal(root);

    for (int i = 0; i < zigzag.size(); i++) {

        cout << zigzag[i] << " ";
    }

    cout << endl;

    cout << "Boundary Traversal: ";

    vector<int> boundary = boundary_traversal(root);

    for (int i = 0; i < boundary.size(); i++) {

        cout << boundary[i] << " ";
    }

    cout << endl;

    cout << "Inorder Traversal: ";

    inorder(root);

    cout << endl;

    cout << "Morris Traversal: ";

    morris_traversal(root);

    cout << endl;

    return 0;
}