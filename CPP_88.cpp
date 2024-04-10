#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class node {

    public:

    int data;
    node *left;
    node *right;

    node (int data) {

        this-> data = data;
        this-> left = NULL;
        this-> right = NULL;
    }
};

node *tree (node *root) {

    cout << "Data: ";

    int data;
    cin >> data;

    root = new node(data);

    if (data == -1) {

        return NULL;
    }

    cout << "Inserting node to the left of " << data << endl;
    root->left = tree(root->left);

    cout << "inserting node to the right of " << data << endl;
    root->right = tree(root->right);

    return root;
}

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

            cout << front-> data << " ";

            if (front->left != NULL)
                q.push(front->left);

            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

int find_position (int inorder[], int inorder_start, int inorder_end, int element) {

    for (int i = inorder_start; i <= inorder_end; i++) {

        if (inorder[i] == element) {

            return i;
        }
    }

    return -1;
}

node *solve (int inorder[], int postorder[], int &index, int inorder_start, int inorder_end, int n) {

    if (index < 0 || inorder_start > inorder_end) {

        return NULL;
    }

    int element = postorder[index--];
    node *root = new node(element);
    int position = find_position(inorder, inorder_start, inorder_end, element);

    root->right = solve (inorder, postorder, index, position + 1, inorder_end, n);
    root->left = solve (inorder, postorder, index, inorder_start, position - 1, n);

    return root;
}

node *build_tree (int inorder[], int postorder[], int n) {

    int postorder_index = n - 1;

    node *answer = solve (inorder, postorder, postorder_index, 0, n - 1, n);

    return answer;
}

void preorder (node *root) {

    if (root == NULL) {

        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node *mapping (node *root, map<node*,node*> &node_to_parent, int target) {

    queue<node*> q;
    q.push(root);

    node_to_parent[root] = NULL;

    node *answer = NULL;

    while (!q.empty()) {

        node *front = q.front();
        q.pop();

        if (front->data == target) {

            answer = front;
        }

        if (front->left != NULL) {

            node_to_parent[front->left] = front;
            q.push(front->left);
        }

        if (front->right != NULL) {

            node_to_parent[front->right] = front;
            q.push(front->right);
        }
    }

    return answer;
}

int burn_tree (node *root, map<node*,node*> &node_to_parent) {

    map<node*,bool> visited;

    queue<node*> q;
    q.push(root);

    visited[root] = true;

    int count = 0;

    while (!q.empty()) {

        bool flag = false;

        int size = q.size();

        for (int i = 0; i < size; i++) {

            node *front = q.front();
            q.pop();

            if (front->left != NULL && !visited[front->left]) {

                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if (front->right != NULL && !visited[front->right]) {

                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (node_to_parent[front] != NULL && !visited[node_to_parent[front]]) {

                flag = true;
                q.push(node_to_parent[front]);
                visited[node_to_parent[front]] = true;
            }
        }

        if (flag == true) {

            count++;
        }
    }

    return count;
}

int min_time (node *root, int target) {

    map<node*,node*> nodeToParent;

    node *target_node = mapping(root, nodeToParent, target);

    int answer = burn_tree(target_node,nodeToParent);

    return answer;
}

int main() {

    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    // 1 2 4 8 -1 -1 -1 5 10 -1 -1 -1 3 -1 7 -1 -1

    node *root;

    root = tree(root);

    cout << endl;

    int inorder[5] = {9, 5, 2, 3, 4};
    int postorder[5] = {5, 9, 3, 4, 2};

    node *answer = build_tree (inorder, postorder, 5);

    cout << "Preorder Traversal: ";
    preorder(answer);
    cout << endl;

    cout << "The time taken to burn the binary tree is: " << min_time(root,8) << endl;

    return 0;
}