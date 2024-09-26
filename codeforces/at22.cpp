#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<int>> coins(H, vector<int>(W, 0));
    for (int i = 0; i < N; ++i) {
        int r, c;
        cin >> r >> c;
        --r; 
        --c;
        coins[r][c] = 1;
    }
    vector<vector<int>> dp(H, vector<int>(W, -1));
    vector<vector<char>> path(H, vector<char>(W, ' '));
    dp[0][0] = coins[0][0];

    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 && j == 0) continue;

            if (i > 0 && dp[i-1][j] != -1) {
                int new_coins = dp[i-1][j] + coins[i][j];
                if (new_coins > dp[i][j]) {
                    dp[i][j] = new_coins;
                    path[i][j] = 'D';
                }
            }

            if (j > 0 && dp[i][j-1] != -1) {
                int new_coins = dp[i][j-1] + coins[i][j];
                if (new_coins > dp[i][j]) {
                    dp[i][j] = new_coins;
                    path[i][j] = 'R';
                }
            }
        }
    }

    cout << dp[H-1][W-1] << endl;

    string result;
    int x = H-1, y = W-1;
    while (x > 0 || y > 0) {
        if (path[x][y] == 'D') {
            result.push_back('D');
            --x;
        } else if (path[x][y] == 'R') {
            result.push_back('R');
            --y;
        }
    }
    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}
