#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 999999

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[MAX][MAX];
    cout << "Enter adjacency matrix (use " << INF << " for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int dist[MAX][MAX];

    // Step 1: Initialize dist matrix same as graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Floyd-Warshall main logic
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Check for negative cycles
    bool hasNegativeCycle = false;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    // Step 4: Output
    if (hasNegativeCycle)
        cout << "\nGraph contains a NEGATIVE weight cycle!\n";
    else {
        cout << "\nAll-Pairs Shortest Path Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    cout << "INF\t";
                else
                    cout << dist[i][j] << "\t";
            }
            cout << endl;
        }
    }

    return 0;
}
