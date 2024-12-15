#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m; 
    vector<int> deg(n + 1, 0); 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int lcount = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            lcount++;
        }
    }
    if (lcount > 2) {
        cout << lcount - 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}

// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> output;
//     if (numRows == 0) return output;
//     output.push_back({1});
//     for (int i = 1; i < numRows; ++i) {
//         vector<int> row(i + 1, 1);  
//         for (int j = 1; j < i; ++j) {
//             row[j] = output[i - 1][j - 1] + output[i - 1][j];
//         }
//      output.push_back(row);
//     }

//     return output;
// }
