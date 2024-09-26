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
        int n;
        cin>>n;
        vector<ll>dp(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>dp[i];
        }
        int maxi=0;
        unordered_map<int,int>mp;
 ll ans=0;
        for(int i=0;i<n;i++)
        {
            mp[dp[i]]++;
            if(mp[dp[i]]>=2 && dp[i]>=maxi)
            {  ans+=dp[i];
                maxi=dp[i];
                
            
            }
            else{
                ans+=dp[i];
            dp[i]=maxi;
            
            }
        }
        mp.clear();
        maxi=0;
         for(int i=0;i<n;i++)
        {
            mp[dp[i]]++;
            if(mp[dp[i]]>=2 && dp[i]>=maxi)
            {    ans+=dp[i];
                 maxi=dp[i];
              
            }
            else{
                ans+=dp[i];
            dp[i]=maxi;
            
            }
        }
       
        for(int i=n-1;i>=0;i--)
        {
            ans+=(1LL)*dp[i]*(n-i);
        }
        cout<<ans<<endl;

    }
    


     return 0;    
}
