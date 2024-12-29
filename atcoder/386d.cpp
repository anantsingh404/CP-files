#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop (int i=0;i<n;i++)
#define MAXN 500005
#define INF 1e9

int main() {
    int K;
    string S, T;
    cin >> K >> S >> T;

    int n = (int)S.size(), m =(int) T.size();
    if(n==0 && m<=K)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
     if(n==0 && m>K)
    {
        cout<<"No"<<endl;
        return 0;
    }
     if(m==0 && n>K)
    {
        cout<<"No"<<endl;
        return 0;
    }
     if(m==0 && n<=K)
    {
        cout<<"Yes"<<endl;
        return 0;
    }



    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }

    if (dp[n][m] <= K) {
        cout << "Yes" << endl;
    } 
    else {
        cout << "No" << endl;
    }

    return 0;
}
