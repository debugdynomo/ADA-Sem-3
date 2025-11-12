#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;  // maximum number of vertices

bool isSafe(int vertex, int color, int V, int colors[], vector<vector<bool>> adj) {
    for (int u = 0; u < V; ++u) {
        if (adj[vertex][u] && colors[u] == color)
            return false;
    }
    return true;
}

bool mColoringBacktrack(int v, int V, int M, int colors[], vector<vector<bool>> adj) {
    if (v == V) return true;
    for (int c = 1; c <= M; ++c) {
        if (isSafe(v, c, V, colors, adj)) {
            colors[v] = c;
            if (mColoringBacktrack(v + 1, V, M, colors, adj))
                return true;
            colors[v] = 0;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, M;
    cin >> V >> E >> M;

    vector<vector<bool>> adj(MAX,vector<bool>(MAX,false));

    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    int colors[MAX];
    for (int i = 0; i < V; ++i)
        colors[i] = 0;

    bool possible = mColoringBacktrack(0, V, M, colors, adj);

    if (!possible)
        cout << "No solution\n";
    else {
        for (int i = 0; i < V; ++i)
            cout << colors[i] << (i + 1 == V ? '\n' : ' ');
    }

    return 0;
}
