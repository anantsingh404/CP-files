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
    ll k;
    cin >>n>>k;
    vector<ll>dp;
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    sort(dp.begin(),dp.end());
    ll ans=0;
    int j=0;
     ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=dp[i];
        while(j<=i && dp[i]-dp[j]>1 || sum >k)
        {
            sum-=dp[j];
            j++;
        }
        ans=max(ans,sum);
    }
    
    
    
   }
return 0;    
}
