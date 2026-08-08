#include <bits/stdc++.h>
using namespace std;

class SolutionRecursive {
public:
    long long climbStairs(int n) {
        if (n <= 2) return n;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

class SolutionDP {
public:
    unordered_map<int, int> memo;

    int climbStairs(int n) {
        if (n <= 2) return n;

        if (memo.count(n))
            return memo[n];

        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return memo[n];
    }
};

int main() {
    int n;
    cin >> n;

    SolutionRecursive recursive;
    SolutionDP dp;

    auto start1 = chrono::high_resolution_clock::now();

    cout << "Recursive: "
         << recursive.climbStairs(n) << endl;

    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();

    cout << "DP: "
         << dp.climbStairs(n) << endl;

    auto end2 = chrono::high_resolution_clock::now();

    auto elapsed1 = chrono::duration_cast<chrono::microseconds>(
        end1 - start1
    );

    auto elapsed2 = chrono::duration_cast<chrono::microseconds>(
        end2 - start2
    );

    cout << "Recursive time: "
         << elapsed1.count() << " us" << endl;

    cout << "DP time: "
         << elapsed2.count() << " us" << endl;
}