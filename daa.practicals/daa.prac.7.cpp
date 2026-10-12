
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);

    // Input coin denominations
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    // Initialize all amounts as unreachable
    vector<int> dp(amount + 1, INT_MAX);

    // Zero coins are needed to make amount zero
    dp[0] = 0;

    // Calculate minimum coins for every amount
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {

            // Check whether this coin can be used
            if (coin <= i && dp[i - coin] != INT_MAX) {

                // Update the minimum number of coins
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Display the result
    if (dp[amount] == INT_MAX) {
        cout << "Change cannot be made." << endl;
    } else {
        cout << "Minimum number of coins: "
             << dp[amount] << endl;
    }

    return 0;
}
