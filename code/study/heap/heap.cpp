#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::vector<int> values = {4, 1, 7, 3, 8, 5};

    // 1. Min-Heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    for (int x : values) {
        min_pq.push(x);
    }

    std::cout << "Min-heap size: " << min_pq.size() << "\n";
    std::cout << "Top element (smallest): " << min_pq.top() << "\n";

    // Standard iteration / draining pattern:
    std::cout << "Popping all elements: ";
    while (!min_pq.empty()) {
        int curr = min_pq.top(); // 1. Read
        min_pq.pop();            // 2. Remove
        std::cout << curr << " ";
    }
    std::cout << "\n"; // Output: 1 3 4 5 7 8

    // 2. Non-destructive inspection (make a copy):
    std::priority_queue<int> max_pq(values.begin(), values.end()); // O(N) constructor
    auto copy_pq = max_pq; // O(N) copy
    
    std::cout << "Inspecting max_pq copy: ";
    while (!copy_pq.empty()) {
        std::cout << copy_pq.top() << " ";
        copy_pq.pop();
    }
    std::cout << "\n"; // Output: 8 7 5 4 3 1

    return 0;
}