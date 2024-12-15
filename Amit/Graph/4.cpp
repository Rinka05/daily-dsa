#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

// Function to check if a number is a power of two
bool isPowerOfTwo(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

// Function to find the minimal permutation
int find_minimal_permutation(int n) {
    vector<int> permutation(n, 0);  // To store the permutation
    set<int> used;  // Set to track used numbers

    // Try to assign values to permutation
    for (int i = 1; i <= n; ++i) {
        bool found = false;

        // Check all possible values of p[i] that make p[i] ^ i a power of two
        for (int p_i = 1; p_i <= n; ++p_i) {
            if (used.find(p_i) == used.end() && isPowerOfTwo(p_i ^ i)) {
                permutation[i - 1] = p_i;
                used.insert(p_i);
                found = true;
                break;
            }
        }

        // If no valid p[i] found, compute the fallback sum
        if (!found) {
            int sum = 0;
            for (int j = 1; j <= n; ++j) {
                sum += (j ^ (n - j + 1));
            }
            return sum;
        }
    }

    // If we successfully formed a valid permutation, compute the sum of p[i] ^ i
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (permutation[i - 1] ^ i);
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << find_minimal_permutation(n) << endl;
    return 0;
}
