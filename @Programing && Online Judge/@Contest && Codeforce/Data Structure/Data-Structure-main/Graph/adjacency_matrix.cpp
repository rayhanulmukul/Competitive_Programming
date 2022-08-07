#include<iostream>

using namespace std;

// Undirected Graph

int main() {
    
    int vertex;
    cout << "Enter number of vertex : ";
    cin >> vertex;

    int edges;
    cout << "Enter Number of edges : ";
    cin >> edges;

    int adjacencyMatrix[vertex][vertex];
    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    
    // Enter edges for Undirected Graph
    cout << "Enter edges : \n";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        if(u > vertex || v > vertex) {
            cout << "Invalid edge!";
            i--;
        }
        else {
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;  // skip this line for directed graph
        }
    }

    // printing adjacency matrix...
    for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
