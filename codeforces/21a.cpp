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
    ll x=n/4;
    ll y=n%4;
    if(y)
    {
        ++x;
    }
    cout<<x<<endl;


    
    
    
   }
return 0;    
}
