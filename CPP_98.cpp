#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include<math.h>
using namespace std;

void dfs (int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adjacent_list, vector<bool> &articulation_point) {

    visited[node] = true;

    disc[node] = low[node] = timer++;

    int child = 0;

    for (auto neighbour : adjacent_list[node]) {

        if (neighbour == parent) {

            continue;

        } else if (!visited[neighbour]) {

            dfs (neighbour, node, timer, disc, low, visited, adjacent_list, articulation_point);

            low[node] = min(low[node],low[neighbour]);

            if (low[neighbour] >= disc[node] && parent != -1) {

                articulation_point[node] = 1;
            }

            child++;

        } else {

            low[node] = min(low[node], disc[neighbour]);
        }
    }

    if (parent == -1 && child > 1) {

        articulation_point[node] = 1;
    }
}

int main() {

    int n = 5;
    int m = 6;

    vector<pair<int,int>> edges;

    edges.push_back(make_pair(1,0));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(1,4));
    edges.push_back(make_pair(2,3));
    edges.push_back(make_pair(2,4));
    edges.push_back(make_pair(3,4));

    unordered_map<int,list<int>> adjacent_list;

    for (int i = 0; i < m; i++) {

        int u = edges[i].first;
        int v = edges[i].second;

        adjacent_list[u].push_back(v);
        adjacent_list[v].push_back(u);
    }

    int timer = 0;

    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    unordered_map<int,bool> visited;

    for (int i = 0; i < n; i++) {

        disc[i] = -1;
        low[i] = -1;
    }

    vector<bool> articulation_point(n,0);

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            dfs (i, parent, timer, disc, low, visited, adjacent_list, articulation_point);
        }
    }

    cout << "The articulation points in the given graph are: ";

    for (int i = 0; i < n; i++) {

        if (articulation_point[i] != 0) {

            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}