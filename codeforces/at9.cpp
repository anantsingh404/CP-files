#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<ll>dp1(n,0);
    vector<ll>dp2(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>dp1[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>dp2[i];
    }
    vector<ll>sum(n,0);
    ll flag=0;
    for(ll i=0;i<n;i++)
    {
      flag+=dp2[i];
      sum[i]=flag; 
    }
    ll m;
    cin>>m;
    vector<ll>ans;
    for(ll i=0;i<m;i++)
    {
        ll a;
        ll b;
        cin>>a>>b;
        ll x=lower_bound(dp1.begin(),dp1.end(),a)-dp1.begin();
        ll y=upper_bound(dp1.begin(),dp1.end(),b)-dp1.begin();
       
            --x;
        
       
            --y;
        if(y<0)
        {
            cout<<0<<endl;
        }
        else if(x<0)
        {
             cout<<sum[y]<<endl;
        }
        else{
 cout<<sum[y]-sum[x]<<endl;
        }
       
    }
    

    
return 0;    
}
