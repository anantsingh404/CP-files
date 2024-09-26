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
        ll x;
        cin>>x;
        vector<ll>dp(n,0);
        for(ll i=0;i<n;i++)
        {
            cin>>dp[i];
        }
        ll toxi=0;
        ll ans=0;
       ll i=0;
       ll j=0;
       while(i<n)
       {
        toxi+=dp[i];
        while(j<i && toxi>x)
        {
            toxi-=dp[j];
            ++j;
        }
        if(toxi<=x)
        {
            ans+=i-j+1;
        }
        if(toxi>x)
        {
            toxi=0;
            i++;
            j=i;
            continue;
        }
        i++;
       }
       cout<<ans<<endl;

    }
    


     return 0;    
}
