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
      ll k;
      cin>>k;
      vector<ll>type(n,0);
      vector<ll>count(n,0);
      for(int i=0;i<n;i++)
      {
        cin>>type[i];
      }
      for(int i=0;i<n;i++)
      {
        cin>>count[i];
      }
      vector<pair<ll,ll>>p;
      for(int i=0;i<n;i++)
      {
        p.push_back({type[i],count[i]});
      }
      sort(p.begin(),p.end());
      ll ans=0;
      for(int i=0;i<n;i++)
      {
        ll x=min(k/p[i].first,p[i].second);
        ans=max(ans,x*p[i].first);
      }
      for(int i=0;i<n-1;i++)
      {
        ll x=min(k/p[i].first,p[i].second);
        ll y=k-x*p[i].first;
        if(p[i].first+1!=p[i+1].first)
        {
            continue;
        }
        ll z=min(y/p[i+1].first,p[i+1].second);
        ll sum=z*p[i+1].first+x*p[i].first;
        ll pq=min({y-z*p[i+1].first,p[i+1].second-z,x});
        
        sum=p[i].first*x+p[i+1].first*z+pq;
        ans=max(ans,sum);
      }
      
    cout<<ans<<endl;



    
    
    
   }
return 0;    
}
