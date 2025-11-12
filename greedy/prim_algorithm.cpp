#include <bits/stdc++.h>
using namespace std;

#define INF 999999
#define MAX 100

int minKey(int key[], bool mstSet[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int n) {
    int totalWeight = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight of MST = " << totalWeight << endl;
}

void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int n;
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, n);

    return 0;
}