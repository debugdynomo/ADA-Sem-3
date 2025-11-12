#include <iostream>
using namespace std;

const int MAXN = 100;
const long long INF = 1e15;

int main() {
    int n, m;
    cin >> n >> m;

    long long adj[MAXN][MAXN];
    long long dist[MAXN];
    bool visited[MAXN];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        if (w < adj[u][v]) adj[u][v] = w;
    }

    int s;
    cin >> s;
    s--;

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[s] = 0;

    for (int iter = 0; iter < n; iter++) {
        int v = -1;
        long long best = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                v = i;
            }
        }
        if (v == -1) break;
        visited[v] = true;

        for (int to = 0; to < n; to++) {
            if (dist[v] + adj[v][to] < dist[to]) {
                dist[to] = dist[v] + adj[v][to];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << -1;
        else cout << dist[i];
        if (i < n-1) cout << " ";
    }
    cout << "\n";

    return 0;
}


/*
Time complexity: O(V^2) for array storage of vertices
                 O((E+V)logV) for min heap & adjacency list

*/