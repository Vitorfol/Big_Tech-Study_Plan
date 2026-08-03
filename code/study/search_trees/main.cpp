#include <iostream>
#include "algorithms.h"

void printVec(const std::string& name, const std::vector<int>& v) {
    std::cout << name << ": ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    // 1. Teste de Grafos (DFS Rec, DFS Pilha, BFS)
    Graph g(5);
    g[0] = {1, 2};
    g[1] = {0, 3};
    g[2] = {0, 4};
    g[3] = {1};
    g[4] = {2};

    std::cout << "=== GRAFOS (DFS e BFS) ===\n";
    std::vector<bool> vis(5, false);
    std::vector<int> res;
    
    dfsRecursive(0, g, vis, res);
    printVec("DFS Recursivo", res);

    res.clear();
    dfsIterative(0, g, res);
    printVec("DFS com Pilha", res);

    res.clear();
    bfs(0, g, res);
    printVec("BFS com Fila", res);

    // 2. Componentes Conexas
    Graph disconnected(6);
    disconnected[0] = {1};
    disconnected[1] = {0};
    disconnected[2] = {3}; // Componente separada
    disconnected[3] = {2};
    // 4 e 5 isolados
    std::cout << "\n=== COMPONENTES CONEXAS ===\n";
    std::cout << "Total de componentes: " << countComponents(disconnected) << "\n";

    // 3. Flood Fill
    std::cout << "\n=== FLOOD FILL ===\n";
    Grid img = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    floodFill(img, 0, 0, 2);
    std::cout << "Matriz apos Flood Fill (de 1 para 2):\n";
    for (const auto& row : img) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }

    // 4. Dijkstra com Heap
    std::cout << "\n=== DIJKSTRA (MIN-HEAP) ===\n";
    WeightedGraph wg(4);
    // Arestas ponderadas: {vizinho, peso}
    wg[0] = {{1, 1}, {2, 4}};
    wg[1] = {{2, 2}, {3, 5}};
    wg[2] = {{3, 1}};
    wg[3] = {};

    std::vector<int> distances = dijkstra(0, wg);
    printVec("Menores distancias a partir do no 0", distances);

    return 0;
}
