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
    ll k;
    cin>>k;
    vector<ll>dp(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>dp[i];
    }
    sort(dp.begin(),dp.end());
    ll alice=0;
    ll bob=0;
    reverse(dp.begin(),dp.end());
    ll sum=0;
    ll temp=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            sum=sum+dp[i];
        }
        else{
            temp=min(k,dp[i-1]-dp[i]);
            dp[i]=dp[i]+temp;
            k=k-temp;
            sum=sum-dp[i];
        }
    }
    cout<<sum<<endl;
    
    



    }
    


     return 0;    
}
