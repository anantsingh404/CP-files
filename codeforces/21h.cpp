#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<ll> dp(n);
        for (int i = 0; i < n; ++i) {
            cin >> dp[i];

        }

        unordered_map<ll, ll> freq;
        for (int i = 0; i < n; ++i) {
            freq[dp[i]]++;

        }

        // Check if all elements are the same and zero
        if (freq.size() == 1 && dp[0] == 0) {
            cout << 0 << endl << endl;
            continue;
        }

        vector<ll> ans;
        bool found = false;

        for (int count = 0; count <= 32; ++count) {
           
        }

        if (found) {
            cout << ans.size() << endl;
            for (ll x : ans) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
