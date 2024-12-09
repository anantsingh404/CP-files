#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input values
    int N, X;
    cin >> N >> X;

    vector<double> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        P[i] /= 100.0; // Convert percentages to probabilities
    }

    // DP array to store the expected number of packs
    vector<double> dp(X + 1, 1e9); // Initialize with large values
    dp[0] = 0; // Base case: 0 rare cards need 0 packs

    // Iterate to update DP for each pack
    for (int pack = 1; pack <= 5000; ++pack) { // Limit iterations for large cases
        vector<double> next_dp(X + 1, 1e9); // Temporary DP for this iteration

        for (int i = 0; i <= X; ++i) { // Calculate contribution for each pack
            for (int j = 0; j < N; ++j) { // Each card contributes independently
                int rare_cards = min(i + 1, X); // Ensure we don't exceed X cards
                next_dp[rare_cards] = min(next_dp[rare_cards], dp[i] + 1);
            }
        }

        // Update the DP array for the next iteration
        dp = next_dp;
    }

    // Output final answer
    cout << fixed << setprecision(8) << dp[X] << endl;

    return 0;
}
