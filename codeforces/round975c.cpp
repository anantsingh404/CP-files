
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
       
     ll n,k;
     cin>>n>>k;
     vector<ll>dp(n,0);
     long long maxi=0;
     for(int i=0;i<n;i++)
     {
        cin>>dp[i];
        maxi=max(maxi,dp[i]);
     }
     
     long long mini=0;
     ll ans=0;
      ll sum=accumulate(dp.begin(),dp.end(),1ll*0);
    for(ll i=n;i>=1;i--)
    {  
       
    ll flag=sum+k;
    if(flag%i>k)
    {
        continue;
    }
     ll x=flag/i;
     if(maxi>x)
    {
        continue;
    }
    else{
        cout<<i<<endl;
        break;
    }
  
    }
    



    
    
    
   }
return 0;    
}
