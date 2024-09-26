#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_ITEMS = 2050;
const int MAX_K = 110;
const int mod = 1e9+7;

int cost[MAX_ITEMS][MAX_K];
int dp[MAX_ITEMS][MAX_K];

void solve() {
    int numItems, maxK;
    cin >> numItems >> maxK;

    
    for (int item = 1; item <= numItems; ++item) {
        int a, b;
        cin >> a >> b;
        cost[item][0] = 0;
        for (int total = 1; total <= maxK; ++total) {
            cost[item][total] = mod;
            for (int rItems = 0; rItems <= total; ++rItems) {
                int cItems = total - rItems;
                if (rItems > a || cItems > b) continue;
                cost[item][total] = min(cost[item][total], rItems * b + cItems * a - rItems * cItems);
            }
        }
    }

    
    for (int i = 0; i <= numItems; ++i) {
        for (int j = 0; j <= maxK; ++j) {
            dp[i][j] = mod;
        }
    }
    dp[0][0] = 0;

    
    for (int item = 0; item < numItems; ++item) {
        for (int used = 0; used <= maxK; ++used) {
            if (dp[item][used] == mod) continue;
            for (int total = used; total <= maxK; ++total) {
                dp[item + 1][total] = min(dp[item + 1][total], dp[item][used] + cost[item + 1][total - used]);
            }
        }
    }

    int result = dp[numItems][maxK];
    if (result == mod) 
    {
        cout<<-1<<endl;
    }else{
    cout << result << endl;
    }
}

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        solve();
    }
    
    return 0;
}
