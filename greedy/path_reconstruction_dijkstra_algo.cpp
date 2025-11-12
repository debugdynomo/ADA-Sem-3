#include <iostream>
using namespace std;

const int MAXN = 100;          // max number of nodes
const long long INF = 1e15;

int main() {
    int n, m;
    cin >> n >> m;

    long long adj[MAXN][MAXN];
    long long dist[MAXN];
    bool used[MAXN];
    int parent[MAXN];   // <-- NEW

    // initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--; // 0-indexed
        if (w < adj[u][v]) adj[u][v] = w;
    }

    int s;
    cin >> s;
    s--; // source 0-indexed

    // initialize arrays
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        used[i] = false;
        parent[i] = -1;   // no parent yet
    }
    dist[s] = 0;

    // Dijkstra
    for (int iter = 0; iter < n; iter++) {
        int v = -1;
        long long best = INF;
        for (int i = 0; i < n; i++) {
            if (!used[i] && dist[i] < best) {
                best = dist[i];
                v = i;
            }
        }
        if (v == -1) break;
        used[v] = true;

        for (int to = 0; to < n; to++) {
            if (dist[v] + adj[v][to] < dist[to]) {
                dist[to] = dist[v] + adj[v][to];
                parent[to] = v;   // remember path
            }
        }
    }

    // Print distances
    cout << "Distances from source:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << "\n";

    // Example: reconstruct path from source s to node t
    int t;
    cin >> t; // target node
    t--; 

    if (dist[t] == INF) {
        cout << "No path\n";
    } else {
        cout << "Path: ";
        int path[MAXN], len = 0;
        for (int v = t; v != -1; v = parent[v]) {
            path[len++] = v;
        }
        // reverse print
        for (int i = len - 1; i >= 0; i--) {
            cout << (path[i] + 1); // back to 1-indexed
            if (i > 0) cout << " -> ";
        }
        cout << "\n";
    }

    return 0;
}
