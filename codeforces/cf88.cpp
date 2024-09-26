#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll solve(ll left,ll right)
{
   return ((right+1)*(right)/2)-((left)*(left-1)/2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--)
    {
       ll a;
       ll k;
        cin>>a>>k;
       ll mini=k;
       ll maxi=a+k-1;
       ll ans=LLONG_MAX;
       
       while(mini<=maxi)
       {
        ll mid=(maxi+mini)/2;
        ll sum1=solve(k,mid);
        ll sum2=solve(mid+1,k+a-1);
        ans=min(ans,abs(sum1-sum2));
        if(sum1>sum2)
        {
         maxi=mid-1;
        }
        else if(sum1==sum2)
        {
         break;
        }
        else{
         mini=mid+1;
        }

         
       }
       cout<<ans<<endl;
      




    
    
    
   }
return 0;    
}
