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
      
    ll n;
    cin>>n;
    
vector<int>dp(n,0);
for(int i=0;i<n;i++)
{
    cin>>dp[i];
}
unordered_map<int,int>mp;
mp[dp[0]]=1;
string ans="YES";
for(int i=1;i<n;i++)
{
    if(mp.find(dp[i]-1)==mp.end() && mp.find(dp[i]+1)==mp.end())
    {
        ans="NO";
        break;
    }
    else{
        mp[dp[i]]++;
    }
}
cout<<ans<<endl;

    }
    


     return 0;    
}
