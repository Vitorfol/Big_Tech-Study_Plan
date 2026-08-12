#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<bool> visited(size, false);
        int num_islands = 0;
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                num_islands++;
                dfs(i, grid, visited);
            }
        }
        return num_islands;
    }

    void dfs(int current, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[current] = true;
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) dfs(neighbor, adj, visited);
        }
    }
};


// main gerada por ia para teste
int main() {
    // Grafo representado por Lista de Adjacência com 6 nós (0 a 5)
    // Nó 0 -> conectado com 1 e 2
    // Nó 1 -> conectado com 0
    // Nó 2 -> conectado com 0
    // Nó 3 -> conectado com 4
    // Nó 4 -> conectado com 3
    // Nó 5 -> sem conexões (isolado)
    vector<vector<int>> adj = {
        {1, 2}, // vizinhos do nó 0
        {0},    // vizinhos do nó 1
        {0},    // vizinhos do nó 2
        {4},    // vizinhos do nó 3
        {3},    // vizinhos do nó 4
        {}      // vizinhos do nó 5
    };

    Solution sol;
    int componentes = sol.numIslands(adj);

    cout << "Numero de componentes conectados: " << componentes << endl;
    cout << "Resultado esperado: 3" << endl;

    return 0;
}