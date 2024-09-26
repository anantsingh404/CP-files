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
       string a;
       cin>>a;
       int n=a.size();
       
       unordered_map<ll,ll>mp;
    long long ans=0;
    ll sum=0;
    mp[0]=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='1')
        {
            ++sum;
        }
        else{
            --sum;
        }
        if(mp.find(sum)!=mp.end() || sum==0)
        {
           ans+=(n-i)*mp[sum];
             mp[sum]+=(i+1);
        }
       else{
        mp[sum]=i+1;
       }      
    }
    cout<<ans<<endl;
    }






    
    
    
   
return 0;    
}
