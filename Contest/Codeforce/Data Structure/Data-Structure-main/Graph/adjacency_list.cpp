#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> adjList;
struct Edge {
    int source, destination;
};

class Graph {
public:      
    Graph(int n) {
        adjList.resize(n+1);
    }
    void addEdge(int src, int dest, int flag) {
        adjList[src].push_back(dest);
        if(flag) {
            adjList[dest].push_back(src);
        }
    }

    void printGraph(int n) {
        for(int i = 0; i <= n; i++) {
            cout << i << "-->";
            for(auto j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    int n;
    cout << "Enter number of vertex : ";
    cin >> n;
    Graph graph(n);

    int e;
    cout << "Enter number of edges : ";
    cin >> e;

    int flag;
    cout << "Enter 0 for directed 1 for undirected : ";
    cin >> flag;

    for(int i = 0; i < e; i++) {
        int src, dest;
        cout << "Enter source and destintion : ";
        cin >> src >> dest;
        graph.addEdge(src, dest, flag);
    }

    graph.printGraph(n);

    return 0;
}
