#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int evaluate(int len, const vector<ll>& seq, ll res) {
    vector<int> dp1(len + 1, 0);
    vector<int> dp2(len + 1, 0);
    dp1[0] = 1; 

    for (int i = 0; i < len; ++i) {
        vector<int> flag1(len + 1, 0);
        vector<int> flag2(len + 1, 0);

        if (dp1[i])
         {
            if (res >= 1) 
            {
                flag2[i + 1] = 1;
            }
            if (i + 1 < len && res >= abs(seq[i + 1] - seq[i])) 
            {
                flag1[i + 2] = 1;
            }
        }

        if (dp2[i] && i + 1 < len && res >= abs(seq[i + 1] - seq[i]))
         {
            flag2[i + 2] = 1;
        }

        for (int j = 0; j <= len; ++j) {
            if (flag1[j]) 
            {
                dp1[j] = 1;
            }
            if (flag2[j])
           {
                dp2[j] = 1;
            }
        }
    }
    if(dp1[len])
    {
        return 1;
    }
    if(dp2[len])
    {
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> dp(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> dp[i];
        }

        ll low = 0, high = 1e18;
        ll ress = high;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (evaluate(n, dp, mid)) 
            {
                ress = mid;
                high = mid - 1;
            }
             else
              {
                low = mid + 1;
            }
        }

        cout << ress << endl;
    }
    return 0;
}
