#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>
#include<vector>
using namespace std;

class graph {

    public:

    unordered_map<int,list<pair<int,int>>> adjacent_list;

    void add_edge (int u, int v, int w) {

        pair<int,int> p = make_pair(v,w);
        adjacent_list[u].push_back(p);
    }

    void print () {

        for (auto i : adjacent_list) {

            cout << i.first << " -> ";

            for (auto j : i.second) {

                cout << "(" << j.first << "," << j.second << ");";
            }

            cout << endl;
        }
    }
};

void dfs (int node, unordered_map<int,list<pair<int,int>>> &adjacent_list, unordered_map<int,bool> &visited, stack<int> &stack) {

    visited[node] = true;

    for (auto neighbour : adjacent_list[node]) {

        if (!visited[neighbour.first]) {

            dfs (neighbour.first, adjacent_list, visited, stack);
        }
    }

    stack.push(node);
}

int main() {

    graph graph_01;

    graph_01.add_edge(0,1,5);
    graph_01.add_edge(0,2,3);
    graph_01.add_edge(1,2,2);
    graph_01.add_edge(1,3,6);
    graph_01.add_edge(2,3,7);
    graph_01.add_edge(2,4,4);
    graph_01.add_edge(2,5,2);
    graph_01.add_edge(3,4,-1);
    graph_01.add_edge(4,5,-2);

    // graph_01.print();

    int n = 6;
    int m = 9;

    unordered_map<int,bool> visited;

    stack<int> stack;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            dfs (i, graph_01.adjacent_list, visited, stack);
        }
    }

    // vector<int> answer;

    // cout << "Topological Sort: ";

    // for (int i = 0; i < n; i++) {

    //     cout << answer[i] << " ";
    // }

    // cout << endl;

    vector<int> distance(n);

    for (int i = 0; i < n; i++) {

        distance[i] = INT16_MAX;
    }

    int src = 1;

    distance[src] = 0;

    while (!stack.empty()) {

        int top = stack.top();
        stack.pop();

        if (distance[top] != INT16_MAX) {

            for (auto i : graph_01.adjacent_list[top]) {

                if (distance[top] + i.second < distance[i.first]) {

                    distance[i.first] = distance[top] + i.second;
                }
            }
        }
    }

    cout << "Shortest Path Array: ";

    for (int i = 0; i < n; i++) {

        if (distance[i] == INT16_MAX) {

            cout << "INF ";

        } else {

            cout << distance[i] << " ";
        }
    }

    cout << endl;

    return 0;
}