#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       
       
       vector<int>dp(n,0);
       int maxi=0;
       for(int i=0;i<n;i++)
       {
        cin>>dp[i];
        //maxi=max(maxi,dp[i]);
       }
       if(n==1)
       {
        cout<<dp[0]+1<<endl;
        continue;
       }
       if(n==2)
       {
        cout<<max(dp[0],dp[1])+1<<endl;
        continue;
       }
       if(n==3)
       {
        cout<<max(max(dp[0],dp[2])+2,dp[1]+1)<<endl;
        continue;
       }
       int ans=0;
       for(int i=0;i<n;i++)
       {
        ans=max(ans,dp[i]+i/2+1+(n-i-1)/2);
       }
       cout<<ans<<endl;

    }
return 0;    
}
