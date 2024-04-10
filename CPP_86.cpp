#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node {

    public: 

    int data;
    node* left;
    node* right;

    node (int data) {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
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

    cout << "Inserting node to the left of " << data << endl;
    root->left = tree(root->left);

    cout << "Inserting node to the right of " << data << endl;
    root->right = tree(root->right);

    return root;
}

void inorder (node* root, int &count) {

    if (root == NULL)
        return;

    inorder(root->left,count);

    if (root->left == NULL && root->right == NULL)
        count++;

    inorder(root->right,count);
}

int leaf_nodes (node* root) {

    int count = 0;

    inorder(root,count);

    return count;
}

int height (node* root) {

    if (root == NULL)
        return 0;
    

    int left = height(root->left);
    int right = height(root->right);

    int answer = max(left,right) + 1;

    return answer;
}

pair<int,int> diameter_and_height (node* root) {

    if (root == NULL) {

        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameter_and_height(root->left);
    pair<int,int> right = diameter_and_height(root->right);

    int diameter_01 = left.first;
    int diameter_02 = right.first;
    int diameter_03 = left.second + right.second + 1;

    pair<int,int> answer;

    answer.first = max(diameter_01,max(diameter_02,diameter_03));
    answer.second = max(left.second,right.second) + 1;

    return answer;
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

            node *front_node = q.front();
            q.pop();

            int index = flag ? i : size - i - 1;
            answer[index] = front_node->data;

            if (front_node->left != NULL)
                q.push(front_node->left);

            if (front_node->right != NULL)
                q.push(front_node->right);
        }

        flag = !flag;

        for (int i = 0; i < size; i++) {

            result.push_back(answer[i]);
        }
    }

    return result;
}

void traverse_left (node *root, vector<int> &answer) {

    if ((root == NULL)  || (root->left == NULL && root->right == NULL))
        return;

    answer.push_back(root->data);

    if (root->left) {

        traverse_left(root->left,answer);

    } else {

        traverse_left(root->right,answer);
    }

}

void traverse_leaf (node *root, vector<int> &answer) {

    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {

        answer.push_back(root->data);
        return;
    }

    traverse_leaf(root->left,answer);
    traverse_leaf(root->right,answer);
}

void traverse_right (node *root, vector<int> &answer) {

    if ((root == NULL)  || (root->left == NULL && root->right == NULL))
        return;

    if (root->right) {

        traverse_right(root->right,answer);

    } else {

        traverse_right(root->left,answer);
    }

    answer.push_back(root->data);

}

vector<int> boundary_traversal (node *root) {

    vector<int> answer;

    if (root == NULL)
        return answer;

    answer.push_back(root->data);

    traverse_left(root->left,answer);

    traverse_leaf(root->left,answer);
    traverse_leaf(root->right,answer);

    traverse_right(root->right,answer);

    return answer;
}

void solve_left (node *root, vector<int> &answer_left, int level) {

    if (root == NULL)
        return;
    
    if (level == answer_left.size())
        answer_left.push_back(root->data);

    solve_left (root->left, answer_left, level + 1);
    solve_left (root->right, answer_left, level + 1);
}

vector<int> left_view (node *root) {

    vector<int> answer_left;

    solve_left (root, answer_left, 0);

    return answer_left;
}

void solve_right (node *root, vector<int> &answer_right, int level) {

    if (root == NULL)
        return;

    if (level == answer_right.size())
        answer_right.push_back(root->data);

    solve_right (root->right, answer_right, level + 1);
    solve_right (root->left, answer_right, level + 1);
}

vector<int> right_view (node *root) {

    vector<int> answer_right;

    solve_right (root, answer_right, 0);

    return answer_right;
}

int find_position (int inorder[], int element, int inorder_start, int inorder_end, int n) {

    for (int i = inorder_start; i <= inorder_end; i++) {

        if (inorder[i] == element) {

            return i;
        }
    }

    return -1;
}

node* solve (int inorder[], int preorder[], int &index, int inorder_start, int inorder_end, int n) {

    if (index >= n || inorder_start > inorder_end) {

        return NULL;
    }

    int element = preorder[index++];
    node* root = new node(element);
    int position = find_position (inorder, element, inorder_start, inorder_end, n);

    root->left = solve (inorder, preorder, index, inorder_start, position - 1, n);
    root->right = solve (inorder, preorder, index, position + 1, inorder_end, n);

    return root;
}

node* build_tree (int inorder[], int preorder[], int n) {

    int preorder_index = 0;

    node *answer = solve (inorder, preorder, preorder_index, 0, n - 1, n);

    return answer;
}

void postorder (node *root) {

    if (root == NULL) {

        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {

    node* root;

    root = tree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << endl;

    cout << "The diameter of the binary tree is: " << diameter_and_height(root).first << endl;
    cout << "The height of the binary tree is: " << diameter_and_height(root).second << endl;
    cout << "The no. of leaf nodes in the binary tree are: " << leaf_nodes(root) << endl;

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

    cout << "Left View: ";

    vector<int> left = left_view(root);

    for (int i = 0; i < left.size(); i++) {

        cout << left[i] << " ";
    }

    cout << endl;

    cout << "Right View: ";

    vector<int> right = right_view(root);

    for (int i = 0; i < right.size(); i++) {

        cout << right[i] << " ";
    }

    cout << endl;

    int inorder[6] = {3, 1, 4, 0, 5, 2};
    int preorder[6] = {0, 1, 3, 4, 2, 5};

    node *answer = build_tree (inorder, preorder, 6);

    cout << "Post Order Travesral: ";
    postorder(answer);
    cout << endl;

    return 0;
}