#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 12;
    cout << "Enter the number of nodes: 12" << "\n";
    cout << "Source: 1" << "\n";
    cout << "Distination: 12" << "\n";


    vector<vector<pair<int,int>>> adjList(n+1);


    adjList[1] = {{2,9},{3,7},{4,3},{5,2}};
    adjList[2] = {{6,4},{7,2},{8,1}};
    adjList[3] = {{6,2},{7,7}};
    adjList[4] = {{8,11}};
    adjList[5] = {{7,11},{8,11}};
    adjList[6] = {{9,6},{10,5}};
    adjList[7] = {{9,4},{10,3}};
    adjList[8] = {{10,5},{11,6}};
    adjList[9] = {{12,4}};
    adjList[10] = {{12,2}};
    adjList[11] = {{12,5}};


    int dest = 12;
    vector<int> cost(n+1, INT_MAX);
    vector<int> d(n+1, -1);

    cost[dest] = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (pair<int,int> edge : adjList[i]) {
            int v = edge.first;
            int c = edge.second;
            if (cost[v] + c < cost[i]) {
                cost[i] = cost[v] + c;
                d[i] = v;
            }
        }
    }

    cout << "Minimum cost from 1 to 12 = " << cost[1] << "\n";



    cout << "Optimal Path: ";
    int temp = 1;
    cout << temp << " -> ";
    while(temp != 12){
        temp = d[temp];
        cout << temp << (temp == 12 ? "" : " -> ");
    }



    return 0;
}