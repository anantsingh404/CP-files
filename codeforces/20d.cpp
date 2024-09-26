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
       vector<ll>dp(n,0);
       for(int i=0;i<n;i++)
       {
        cin>>dp[i];
       }
       ll count=0;
       long long prev=1;
       for(int i=1;i<n;i++)
       {
        if(dp[i]==1 && dp[i]<dp[i-1])
        {
            count=-1;
            break;
        }
double x=double(prev*log(dp[i-1]));
double y=double(log(dp[i]));
double z=double(x/y);
if(z<=1)
{
    prev=1;

}
else if(z>1)
{
    ll x=1;
    ll flag=1;
    while(x<z)
    {  flag*=2;
        ++count;
        x*=2;
    }
    prev=flag;
   }
}
cout<<count<<endl;
}
return 0;    
}
