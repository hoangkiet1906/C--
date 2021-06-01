#include<bits/stdc++.h>
using namespace std;

int graph[5][5];

void printGraph(int n){
    cout << "The graph is:" << endl;
    for (int i = 0; i < n; i++){
        cout << i << " -> ";
        for (int j = 0; j < n; j++){
            if (graph[i][j] == 1)
                cout << j << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int nodes, edges;
    cout<<"Nhap so nut va canh cua ma tran 5x5: ";
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    printGraph(5);
    return 0;
}
