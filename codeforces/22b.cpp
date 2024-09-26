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
        vector<ll>dp(n-1);
        for(int i=0;i<n-1;i++)
        {
            cin>>dp[i];
        }
        vector<int>ans(n,0);
        for(int i=0;i<n-1;i++)
        {
            ll x=dp[i];
            int j=0;
            while(j<64)
            {
              if(x&(1<<j))
              {
             ans[i]=ans[i]|(1<<j);
            ans[i+1]=ans[i+1]|(1<<j);
               }
              ++j;
            }
        }
        bool flag=true;
        for(int i=0;i<n-1;i++)
        {
            if((ans[i]&ans[i+1])!=dp[i])
            {
             flag=false;
             break;
            }
        }
        if(!flag)
        {
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;



    
    
    
   }
return 0;    
}
