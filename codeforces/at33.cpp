#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll solve(vector<ll>&dp,vector<vector<ll>>&dp2,int i,int count)
{
    if(i>=dp.size())
    {
        return 0;
    }
    if(dp2[i][count%2]!=-1)
    {
        return dp2[i][count%2];
    }
    ll ans=0;
    if((count+1)%2==0)
    {
        ans=2*dp[i]+solve(dp,dp2,i+1,count+1);
    }
    if((count+1)%2==1)
    {
        ans=max(ans,dp[i]+solve(dp,dp2,i+1,count+1));
    }
    ans=max(ans,solve(dp,dp2,i+1,count));
    return dp2[i][count%2]=ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //write your code here
   ll n;
   cin>>n;
   vector<ll>dp(n,0);
   for(int i=0;i<n;i++)
   {
    cin>>dp[i];
   }
   vector<vector<ll>>dp1(n,vector<ll>(2,-1));
   ll x=solve(dp,dp1,0,0);
   cout<<x<<endl;


     return 0;    
}
