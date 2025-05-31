#include <bits/stdc++.h>
using namespace std;

int main(){
    int vertex;
    cout << "Enter number of Vertex : ";
    cin >> vertex;
     
    int edge;
    cout << "Enter Nubmer of Edge : ";
    cin >> edge;

    int adjMat[vertex][vertex];
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            adjMat[i][j] = 0;
        }
    }

    // Enter edges for undirected graph
    cout << "Enter edges : \n";
    for(int i = 0; i < edge; i++){
        int u, v;
        cin >> u >> v;
        if(u > vertex || v > vertex){
            cout << "Invalid Edge!";
            i--;
        }else{
            adjMat[u][v] = 1;
            adjMat[v][u] = 1;
        }
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}