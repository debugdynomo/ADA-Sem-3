#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;

bool isSafe(int v, int graph[MAX][MAX], int path[], int pos, int V) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; ++i)
        if (path[i] == v) return false;
    return true;
}

bool solveHamiltonian(int graph[MAX][MAX], int path[], int pos, int V) {
    if (pos == V)
        return graph[path[pos - 1]][path[0]] == 1;

    for (int v = 1; v < V; ++v) {
        if (isSafe(v, graph, path, pos, V)) {
            path[pos] = v;
            if (solveHamiltonian(graph, path, pos + 1, V))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;

    int graph[MAX][MAX];
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    int path[MAX];
    for (int i = 0; i < V; ++i)
        path[i] = -1;
    path[0] = 0;

    if (!solveHamiltonian(graph, path, 1, V)) {
        cout << "No Hamiltonian Cycle\n";
        return 0;
    }

    cout << "Hamiltonian Cycle:\n";
    for (int i = 0; i < V; ++i)
        cout << path[i] + 1 << " ";
    cout << path[0] + 1 << "\n";

    return 0;
}
