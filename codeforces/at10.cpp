#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<ll>dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    unordered_map<ll,int>mp;
    ll sum=0;
    vector<ll>ans(n,0);
    mp[dp[0]]++;
    ans[0]=1;
    sum+=1;
    unordered_map<int,int>mp1;
    for(int i=1;i<n;i++)
    {
        if(mp.find(dp[i])==mp.end())
        {  mp1[dp[i]]=i;
           mp[dp[i]]++;
          ans[i]=ans[i-1]+i+1; 
          sum+=ans[i]; 
        }
        else{
            
            ans[i]=ans[i-1]+(i-mp1[dp[i]]);
            mp1[dp[i]]=i;
            sum+=ans[i];

        }
    }
    cout<<sum<<endl;
    
return 0;    
}
