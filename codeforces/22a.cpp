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
    vector<int>dp(n);
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
        if(i%2==0)
        {
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans<<endl;


    
    
    
   }
return 0;    
}
