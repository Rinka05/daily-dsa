#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007


vector<unordered_map<int, int>> prefix_freq;
void precompute_prefix_freq(vector<int>& a, int n) {
    prefix_freq.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_freq[i] = prefix_freq[i - 1];
        prefix_freq[i][a[i - 1]]++;          
    }
}
bool is_good_subarray(int l, int r, int k) {
    unordered_map<int, int> subarray_freq;
    for (auto& p : prefix_freq[r]) {
        int freq = p.second - prefix_freq[l - 1][p.first];
        if (freq > 0) subarray_freq[p.first] = freq;
    }
    for (auto& p : subarray_freq) {
        if (p.second != k) return false;
    }
    return true;
}
int get_answer(int n, int k, vector<int>& a, int q, vector<vector<int>>& queries) {
    precompute_prefix_freq(a, n);

    int sumOfIndices = 0;
    for (int i = 0; i < q; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        if (is_good_subarray(l, r, k)) {
            sumOfIndices = (sumOfIndices + (i + 1)) % MOD;
        }
    }
    return sumOfIndices;
}
