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
       
     ll n,q;
     cin>>n>>q;
     vector<ll>ans;
     for(int i=0;i<n;i++)
     { 
         ll x;
     cin>>x;
        ans.push_back(x);
     }
     sort(ans.begin(),ans.end());
     unordered_map<ll,ll>mp;
     for(int i=0;i<n;i++)
     {
        ll x=1ll*(i)*(n-i-1)+(i)+(n-i-1);
        
        mp[x]++;

     }
     for(int i=1;i<n;i++)
     {
      ll x=(i)*(n-i);
      mp[x]+=ans[i]-ans[i-1]-1;
     }
     while(q--)
     {
        ll x;
        cin>>x;
        cout<<mp[x]<<" ";
        



     }
     cout<<endl;



    
    
    
   }
return 0;    
}
