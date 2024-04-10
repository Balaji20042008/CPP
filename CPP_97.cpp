#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map> 
#include<limits.h>
#include<list>
using namespace std;

class graph {

    public:

    unordered_map<int,list<pair<int,int>>> adjacent_list;

    void add_edge (int u, int v, int w) {

        adjacent_list[u].push_back(make_pair(v,w));
        adjacent_list[v].push_back(make_pair(u,w));
    }

    void print () {

        for (auto i : adjacent_list) {

            cout << i.first << " -> ";

            for (auto j : i.second) {

                cout << "[" << j.first << "," << j.second << "] ";
            }

            cout << endl;
        }
    }
};

int main() {

    graph graph_01;

    graph_01.add_edge(0,1,2);
    graph_01.add_edge(0,3,6);
    graph_01.add_edge(1,2,3);
    graph_01.add_edge(1,3,8);
    graph_01.add_edge(1,4,5);
    graph_01.add_edge(2,4,7);

    graph_01.print();

    cout << endl;

    int n = 5;

    vector<int> key(n);
    vector<bool> mst(n);
    vector<int> parent(n);

    for (int i = 0; i < n; i++) {

        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n; i++) {

        int min = INT_MAX;

        int u;

        for (int v = 0; v < n; v++) {

            if (mst[v] == false && key[v] < min) {

                u = v;
                min = key[v];
            }
        }

        mst[u] = true;

        for (auto it : graph_01.adjacent_list[u]) {

            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v]) {

                parent[v] = u;
                key[v] = w;
            }
        }
    }

    graph graph_02;

    for (int i = 1; i < n; i++) {

        graph_02.add_edge(parent[i],i,key[i]);
    }

    graph_02.print();

    return 0; 
}