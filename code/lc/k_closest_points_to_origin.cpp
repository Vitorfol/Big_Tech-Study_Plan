#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>
        > pq;
        
        for (int i=0; i<points.size(); i++) {
            int dist_fds = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist_fds, {points[i][0], points[i][1]}});
        }

        vector<vector<int>> response(k);
        int index = 0;

        while (k--) {
            auto [dist, posicao_2d] = pq.top();
            auto [x, y] = posicao_2d;
            pq.pop();
            response[index].push_back(x);
            response[index].push_back(y);
            index++;
        }
        return response;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points1 = {{1, 3}, {-2, 2}};
    int k1 = 1;
    auto res1 = sol.kClosest(points1, k1);
    cout << "Resultado Teste 1:\n";
    for (const auto& p : res1) {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << "\n\n";

    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;
    auto res2 = sol.kClosest(points2, k2);
    cout << "Resultado Teste 2:\n";
    for (const auto& p : res2) {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << "\n";

    return 0;
}
