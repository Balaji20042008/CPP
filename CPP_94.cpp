#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph {

    public:

    unordered_map<int,list<int>> adjacent;

    void add_edge (int u, int v, bool direction) {

        adjacent[u].push_back(v);

        if (direction == 0) {

            adjacent[v].push_back(u);
        }
    }

    void adjacent_list () {

        for (auto i : adjacent) {

            cout << i.first << " -> ";

            for (auto j : i.second) {

                cout << j << " ";
            }

            cout << endl;
        } 
    }
};

int main() {

    int n;

    cout << "The number of nodes are: ";
    cin >> n;

    int m;

    cout << "The number of edges are: ";
    cin >> m;

    cout << "The edges are connected in the following way: " << endl;

    graph graph_01;

    for (int i = 0; i < m; i++) {

        int u;
        int v;

        cin >> u;
        cin >> v;
        
        graph_01.add_edge(u,v,0);
    }

    cout << "The adjacent list of the graph: " << endl;

    graph_01.adjacent_list();
 
    return 0;
}