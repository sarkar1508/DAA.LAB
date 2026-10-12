
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    // Input dimensions of all matrices
    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    // dp[i][j] stores minimum cost to multiply matrices i to j
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Consider chains of increasing length
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;

            // Initially, assume the cost is infinite
            dp[i][j] = INT_MAX;

            // Try every possible splitting position
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                // Store the minimum multiplication cost
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Display the minimum cost
    cout << "Minimum number of multiplications: "
         << dp[1][n] << endl;

    return 0;
}
