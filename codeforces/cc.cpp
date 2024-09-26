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
      
    ll n;
    cin>>n;
    ll a,b;
    cin>>a>>b;
    
    vector<ll>dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    
    sort(dp.begin(),dp.end());
    long long ans=dp[n-1]-dp[0];
    long long x=__gcd(a,b);
    for(int i=0;i<n;i++)
    {
      dp[i]=dp[i]%x;
    }
    sort(dp.begin(),dp.end());
    ans=min(ans,dp[n-1]-dp[0]);
    for(int i=0;i<n-1;i++)
    {
        long long y=dp[i]+x;
        long long temp=abs(y-dp[i+1]);
        ans=min(ans,temp);
    }

   cout<<ans<<endl;
    
    



    }
    


     return 0;    
}
