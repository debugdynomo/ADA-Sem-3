#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w; // from u to v with weight w
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edgeList: ";
    cin >> E;

    Edge edgeList[1000]; // assuming max 1000 edgeList (you can increase as needed)

    cout << "Enter edgeList (u v w): \n";
    for (int i = 0; i < E; i++) {
        cin >> edgeList[i].u >> edgeList[i].v >> edgeList[i].w;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    // Step 1: Initialize distances
    int dist[100];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    // Step 2: Relax edgeList V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edgeList[j].u;
            int v = edgeList[j].v;
            int w = edgeList[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Check for negative weight cycle
    bool hasNegativeCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edgeList[j].u;
        int v = edgeList[j].v;
        int w = edgeList[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle)
        cout << "\nGraph contains a NEGATIVE weight cycle!\n";
    else {
        cout << "\nShortest distances from source " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";
            if (dist[i] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i];
            cout << endl;
        }
    }

    return 0;
}
