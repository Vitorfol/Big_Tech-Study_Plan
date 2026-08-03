#include "algorithms.h"
#include <stack>
#include <queue>
#include <iostream>

// 1. DFS Recursivo
void dfsRecursive(int u, const Graph& adj, std::vector<bool>& visited, std::vector<int>& out) {
    visited[u] = true;
    out.push_back(u);
    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited, out);
        }
    }
}

// 1. DFS Iterativo com Pilha (std::stack)
void dfsIterative(int start, const Graph& adj, std::vector<int>& out) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            visited[u] = true;
            out.push_back(u);

            // Empilha os vizinhos na ordem reversa para preservar a ordem visual esquerda-direita
            for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
                int neighbor = adj[u][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
}

// 1. BFS com Fila (std::queue)
void bfs(int start, const Graph& adj, std::vector<int>& out) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        out.push_back(u);

        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// 2. Contar Componentes Conexas
int countComponents(const Graph& adj) {
    int n = adj.size();
    std::vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components++;
            std::vector<int> dummy;
            dfsRecursive(i, adj, visited, dummy);
        }
    }
    return components;
}

// 3. Flood Fill em Matriz 2D
void floodFill(Grid& image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor == newColor) return;

    int rows = image.size();
    int cols = image[0].size();
    std::queue<std::pair<int, int>> q;
    
    q.push({sr, sc});
    image[sr][sc] = newColor;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == originalColor) {
                image[nr][nc] = newColor;
                q.push({nr, nc});
            }
        }
    }
}

// 4. Dijkstra com Heap (std::priority_queue)
std::vector<int> dijkstra(int start, const WeightedGraph& adj) {
    int n = adj.size();
    std::vector<int> dist(n, 1e9); // Infinito simulado
    
    // Min-heap armazena pares de {distancia, no}
    // std::priority_queue por padrão é Max-Heap em C++, usamos std::greater para Min-Heap
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Caminho obsoleto, ignora

        for (auto& edge : adj[u]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[neighbor]) {
                dist[neighbor] = dist[u] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}
