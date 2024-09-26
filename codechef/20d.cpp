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
        ll n;
        cin >> n;
        vector<int> dp(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> dp[i];
            mp[dp[i]]++;
        }
        
        int m = mp.size();
        vector<int> flag(n);
        unordered_map<int, int> mp1;
        
        for (int i = n - 1; i >= 0; i--) {
            mp1[dp[i]]++;
            flag[i] = mp1.size();
        }

        int count = 0;
        vector<int> ans;
        int even = 0;
        int i = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int prev = -1;
        set<int>st;
        while (i < n) {
            if (even == 0 && flag[i] > m - ans.size() - 1) {
                if (dp[i] > maxi && !st.count(dp[i])) {
                    maxi = dp[i];
                    prev = i;
                    
                }
                i++;
            } else if (even == 0 && flag[i] == m - ans.size() - 1) {
                ans.push_back(prev);
                st.insert(dp[prev]);
                int x=prev;
                while(x<n && mp.count(dp[x]))
                {
                    ++x;
                }
                i = x ;
                even = 1;
                maxi = INT_MIN;
            } 
            else if (even == 1 && flag[i] > m - ans.size() - 1) {
                if (dp[i] < mini &&  !st.count(dp[i])) {
                    mini = dp[i];
                    prev = i;
                    
                }
                i++;
            } else if (even == 1 && flag[i] == m - ans.size() - 1) {
                ans.push_back(prev);
                 st.insert(dp[prev]);
                int x=prev;
                while(x<n && mp.count(dp[x]))
                {
                    ++x;
                }
                i = x ;
                even = 0;
               
                mini = INT_MAX;
            }
        }
        if (ans.size()<m) {
            ans.push_back(prev);
        }

        cout << m << endl;
        for (int idx : ans) {
            cout << dp[idx] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
