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
      ll m;
      cin>>m;
      ll k;
      cin>>k;
    ll a;
    ll b;
    if(n%k)
    {
        a=n/k+1;
    }
    if(n%k==0)
    {
        a=n/k;
    }
    if(m%k==0)
    {
       b=m/k;
    }
    if(m%k)
    {
        b=m/k+1;
    }
    ll ans=a+b+abs(b-a);
    if(b<a)
    {
        --ans;
    }
    cout<<ans<<endl;
      
      
      
      }
       

    
    
    
   }
 

