#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
unordered_map<int, int> mp;

int solve(int idx, vector<vector<int> >&adj) {
    int temp = 0;
    bool flag = false;
    for (auto itr : adj[idx]) {
        if (itr != idx) {
            if (mp.find(itr) != mp.end()) {
                flag = true;
            }
            temp += solve(itr, adj);
        }
    }
    if (flag || temp) {
        return temp + 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    vector<int> dp(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> dp[i];
        --dp[i];
        mp[dp[i]]++;
    }

    int x = solve(dp[0], adj);
    cout << x << endl;

    return 0;
}
