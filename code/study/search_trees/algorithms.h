#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <string>

// Graph & Grid standard definitions
using Graph = std::vector<std::vector<int>>;
using WeightedGraph = std::vector<std::vector<std::pair<int, int>>>; // pair<neighbor, weight>
using Grid = std::vector<std::vector<int>>;

// 1. DFS & BFS Traversals
void dfsRecursive(int u, const Graph& adj, std::vector<bool>& visited, std::vector<int>& out);
void dfsIterative(int start, const Graph& adj, std::vector<int>& out);
void bfs(int start, const Graph& adj, std::vector<int>& out);

// 2. Connected Components
int countComponents(const Graph& adj);

// 3. Flood Fill (Matrix 2D)
void floodFill(Grid& image, int sr, int sc, int newColor);

// 4. Dijkstra Shortest Path (Weighted Graph using Min-Heap / Priority Queue)
std::vector<int> dijkstra(int start, const WeightedGraph& adj);

#endif // ALGORITHMS_H
