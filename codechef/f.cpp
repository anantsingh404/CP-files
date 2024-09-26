#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+7;
const int mod=1e9+7;
ll factorial[N+1];
ll inverse[N+1];
   
ll binpow(ll base,ll ex)
{
    if(ex<0)
      return 0ll;
    ll ans=1;
    while(ex>0)
    {
        if(ex%2==1)
                ans=(ans*base)%mod;
        base=(base*base)%mod;
        ex=ex/2;
    }
    return ans;
}
 
void pre()
{
   factorial[0]=1;
   inverse[0]=1;
   for(int i=1;i<=N;i++)
       factorial[i]=(factorial[i-1]*i)%mod;
   
   inverse[N]=binpow(factorial[N],mod-2);
   for(int i=N-1;i>=0;i--)
      inverse[i]=(inverse[i+1]*(i+1ll))%mod;
}
 
ll nCr(int n , int r)
{
    if(n<0 || r<0 || n<r)
            return 0;
    ll ans=1;
    ans=factorial[n];
    ans=(ans*inverse[n-r])%mod;
    ans=(ans*inverse[r])%mod;
    return ans;
}
 
ll nPr(int n, int r)
{
    if(n<0 || r<0 || n<r)
                return 0;
    ll ans=1;
    ans=factorial[n];
    ans=(ans*inverse[n-r])%mod;
    return ans;
}
void solve(){
    
    int n,k;
    cin >> n >> k;
 
    int ones=0;
    for(int i=0;i<n;i++)
    {
        int ex;
        cin >> ex;
        ones+=(ex==1);
    }
 
    int zeros=n-ones;
    long long ans=0ll;
    for(int i=(k+1)/2;i<=k;i++)
        ans=(ans+nCr(ones,i)*nCr(zeros,k-i))%mod;
 
    cout << ans << "\n";
} 
 
 
int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);
    pre();
    int t=1;  cin>>t;
    for(int i=1;i<=t;i++){
       
        solve();
    }
}