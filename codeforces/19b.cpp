#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
    ll t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        --x;
        --y;
       vector<int>dp(n,0);
        for(int i=y;i<=x;i++)
        {
            dp[i]=1;
        }
        int tt=-1;
        for(int i=y-1;i>=0;i--)
        {
dp[i]=tt;
tt=-1*tt;
        }
        int cur=-1;
        for(int i=x+1;i<n;i++)
        {
            dp[i]=cur;
            cur=-1*cur;
        }
        for(int i=0;i<n;i++)
        {
            cout<<dp[i]<<" ";
        }
    }
    


     return 0;    
}
