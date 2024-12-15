#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
long long lcm(long long a, long long b) {
    return (a * b) / __gcd(a, b);
}
int get_answer(int n, vector<int> a, vector<int> par) {
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        if (par[i - 1] != 0) {
            adj[par[i - 1]].push_back(i);
        }
    }
    long long total_lcm = 1;
    for (int i = 1; i <= n; i++) {
        total_lcm = lcm(total_lcm, a[i - 1]);
    }
    vector<long long> subtree_lcm(n + 1, 0);
    function<void(int)> dfs = [&](int node) {
        long long current_lcm = a[node - 1];  
        for (int child : adj[node]) {
            dfs(child);
            current_lcm = lcm(current_lcm, subtree_lcm[child]);
        }
        subtree_lcm[node] = current_lcm;
    };
    dfs(1);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        long long rem_lcm = total_lcm / subtree_lcm[i]; 
        if (subtree_lcm[i] == rem_lcm) {
         count++;
        }
    }

    return count;
}

int main() {
    // Test Case 1
    int n1 = 1;
    vector<int> a1 = {1};  // Values of the nodes
    vector<int> par1 = {0};  // Parent array: node 1 has no parent (root)
    cout << get_answer(n1, a1, par1) << endl;  // Expected Output: 0

    // Test Case 2
    int n2 = 2;
    vector<int> a2 = {4, 4};  // Values of the nodes
    vector<int> par2 = {0, 1};  // Parent array: node 1 is the root, node 2's parent is node 1
    cout << get_answer(n2, a2, par2) << endl;  // Expected Output: 1

    return 0;
}
